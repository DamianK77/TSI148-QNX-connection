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
    //TSI148_map_structure((struct register_info *)reginfo);

    reginfo=TSI148_map_structure((struct register_info *)reginfo);
    printf("Read value from VENI field from main : 0x%08X\n", reginfo->VENI);
    return EXIT_SUCCESS;
}

