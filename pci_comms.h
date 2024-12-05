#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <string.h>

read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line);