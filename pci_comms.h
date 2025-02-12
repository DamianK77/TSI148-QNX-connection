#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <string.h>
#include <tsi_struct.h>

#include <sys/mman.h>
#include <stdint.h>
#include <errno.h>
#define BASE_ADDRESS_L_OFFSET 0x10
#define BASE_ADDRESS_H_OFFSET 0x14
#define INTERRUPT_LINE_OFFSET 0x3C
#define CRG_SIZE 0x1000 // 4 Kbyte size 

/// @brief Maps virtual memory into structure of registers.
struct register_info* TSI148_map_structure(uint8_t *error);

/// @brief Read TSI148 PCI configuration, writes to pci_config_base_address and pci_interrupt_line.
/// @param pci_config_base_address pointer to uint64_t variable to store base address
/// @param pci_interrupt_line pointer to uint8_t variable to store interrupt line
int read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line);

/**
 * @brief Map Tsi148 registers into virtual memory.
 * 
 * @param base_address The physical base address of the register group.
 * @param size The size of the memory region to map.
 * @return uint64_t Address of mapped virtual memory, or NULL on failure.
 */
uint64_t map_tsi148_registers(uint64_t base_address, size_t size);
