#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
//#include <tsi_mapping.h>
#include <string.h>
//#include <tsi_struct.h>
#include <pci_comms.h>


int main(void) {

    struct register_info *reginfo;

    uint8_t error = 0;
    reginfo=TSI148_map_structure(&error);
    if (error != 0) {
    	printf("Error, exited with error code %d\n", error)
    }
    printf("Read value from VENI field from main : 0x%08X\n", reginfo->VENI);
    printf("Read value from DEVI field from main : 0x%08X\n", reginfo->DEVI);
    printf("Read value from OTAT0 field from main : 0x%08X\n", reginfo->OTAT0);
    reginfo->OTAT0=0x00100000;
    printf("Read value from OTAT0 field from main : 0x%08X\n", reginfo->OTAT0);

    return EXIT_SUCCESS;
}

