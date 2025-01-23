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
struct register_info* TSI148_map_structure(uint8_t *error);
int read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line);
uint64_t map_tsi148_registers(uint64_t base_address, size_t size);
static inline void unmap_tsi148_registers(void *mapped_base, size_t size);
