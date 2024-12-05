#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <string.h>

#define BASE_ADDRESS_L_OFFSET 0x10
#define BASE_ADDRESS_H_OFFSET 0x14
#define INTERRUPT_LINE_OFFSET 0x3C

int read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line);

int main(void) {
    uint64_t pci_config_base_address = 0;
    uint8_t pci_interrupt_line = 0;

    if (read_TSI148_pci_config(&pci_config_base_address, &pci_interrupt_line) != 0) {
        fprintf(stderr, "Błąd podczas odczytu konfiguracji PCI\n");
        return EXIT_FAILURE;
    }

    printf("Base Address: 0x%lX\n", pci_config_base_address);
    printf("Interrupt Line: %u\n", pci_interrupt_line);

    return EXIT_SUCCESS;
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

        pci_detach_device(hdl);
    }

    /* Disconnect from the PCI server */
    pci_detach(phdl);

    *pci_config_base_address = ((uint64_t)pci_config_base_buffH << 32) | pci_config_base_buffL;

    return 0;
}
