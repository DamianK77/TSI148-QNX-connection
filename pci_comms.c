#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <string.h>
#include <tsi_struct.h>
#include "pci_comms.h"

#include <sys/mman.h>
#include <stdint.h>
#include <errno.h>




struct register_info* TSI148_map_structure(uint8_t *error) {
    uint64_t pci_config_base_address = 0;
    uint8_t pci_interrupt_line = 0;

    *error = 0;

    if (read_TSI148_pci_config(&pci_config_base_address, &pci_interrupt_line) != 0) {
        fprintf(stderr, "Błąd podczas odczytu konfiguracji PCI\n");
        *error = 1;
        return EXIT_FAILURE;
    }

    printf("Base Address: 0x%lX\n", pci_config_base_address);
    printf("Interrupt Line: %u\n", pci_interrupt_line);

    //memory mapping test
    uint64_t memory_mapped = map_tsi148_registers(pci_config_base_address, CRG_SIZE);
    if (!memory_mapped) {
        printf("Failed to map memory\n");
        *error = 2;
        return 1;
    }
//     struct register_info *reg_info = (struct register_info *)memory_mapped;

    //printf("Read value from VENI field : 0x%08X\n", reg_info->VENI);
     printf("Read value from VENI field : 0x%08X\n", ((struct register_info *)memory_mapped)->VENI);

    // map the structure to the memory
    return (struct register_info *)memory_mapped;


    // unmap_tsi148_registers(memory_mapped, CRG_SIZE);
    //return 0;
}

/// @brief Read TSI148 PCI configuration, writes to pci_config_base_address and pci_interrupt_line.
/// @param pci_config_base_address pointer to uint64_t variable to store base address
/// @param pci_interrupt_line pointer to uint8_t variable to store interrupt line
/// @return
int read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line) {

    int pidx; // PCI device index
    void *hdl; // PCI device handle
    int phdl; // PCI handle
    struct pci_dev_info inf; // PCI device info structure
    uint32_t pci_config_base_buffL = 0; // PCI configuration base address buffer
    uint32_t pci_config_base_buffH = 0; // PCI configuration base address buffer

    // root access
    if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
        perror("ThreadCtl");
        return EXIT_FAILURE;
    }

    /* Connect to the PCI server */
    phdl = pci_attach(0);
    if (phdl == -1) {
        fprintf(stderr, "Unable to initialize PCI\n");
        return EXIT_FAILURE;
    }

    /* Initialize the pci_dev_info structure */
    memset(&inf, 0, sizeof(inf));
    pidx = 0;
    inf.VendorId = 0x10E3;
    inf.DeviceId = 0x0148;

    hdl = pci_attach_device(NULL, PCI_INIT_ALL, pidx, &inf);
    if (hdl == NULL) {
        fprintf(stderr, "Unable to locate adapter\n");
        pci_detach(phdl);
        return EXIT_FAILURE;
    } else {

        /* Read base address from PCI configuration space */
        pci_read_config32(inf.BusNumber, inf.DevFunc, BASE_ADDRESS_L_OFFSET, 1, &pci_config_base_buffL);
        pci_read_config32(inf.BusNumber, inf.DevFunc, BASE_ADDRESS_H_OFFSET, 1, &pci_config_base_buffH);
        /* Read interrupt line from PCI configuration space */
        pci_read_config8(inf.BusNumber, inf.DevFunc, INTERRUPT_LINE_OFFSET, 1, pci_interrupt_line);

        *pci_config_base_address = ((uint64_t)pci_config_base_buffH << 32) | pci_config_base_buffL;
        *pci_config_base_address &= ~0xfff; // mask to match 4kB memory page

        pci_detach_device( hdl );
    }

    /* Disconnect from the PCI server */
    pci_detach(phdl);

    return 0;
}
/**
 * @brief Map Tsi148 registers into virtual memory.
 * 
 * @param base_address The physical base address of the register group.
 * @param size The size of the memory region to map.
 * @return void* Pointer to the mapped virtual memory, or NULL on failure.
 */
uint64_t map_tsi148_registers(uint64_t base_address, size_t size) {
    // Ensure the thread has I/O privileges
    if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
        perror("ThreadCtl failed");
        return NULL;
    }

    // Map the physical memory
    uint64_t mapped_base = mmap_device_memory(
        NULL,                // Virtual address (NULL for auto)
        size,                // Size of the memory block
        PROT_READ | PROT_WRITE, // Read/Write permissions
        MAP_SHARED,          // Shared mapping
        base_address         // Physical address to map
    );

    if (mapped_base == MAP_FAILED) {
        perror("mmap_device_memory failed");
        return NULL;
    }

    return mapped_base;
}

/**
 * @brief Unmap Tsi148 registers from virtual memory.
 * 
 * @param mapped_base Pointer to the mapped virtual memory.
 * @param size The size of the memory region to unmap.
 */
static inline void unmap_tsi148_registers(void *mapped_base, size_t size) {
    if (mapped_base) {
        munmap(mapped_base, size);
    }
}
