#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <string.h>
#include <tsi_struct.h>

#define BASE_ADDRESS_L_OFFSET 0x10
#define BASE_ADDRESS_H_OFFSET 0x14
#define INTERRUPT_LINE_OFFSET 0x3C
struct register_info* TSI148_map_structure(struct register_info *reg_info);
int read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line);
