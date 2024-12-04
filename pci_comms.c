#include <hw/pci.h>
#include <hw/pci_devices.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <tsi_struct.h>


long offset = offset_of(struct register_info, SUBI);
// print offset of subi in hex
printf("offset of SUBI: %lx\n", offset);

int main( void )
{
    int pidx;
    void* hdl;
    int phdl;
    struct pci_dev_info inf;
    uint32_t pci_config_base_buffL = 0;
    uint32_t pci_config_base_buffH = 0;

    // root access
    ThreadCtl(_NTO_TCTL_IO, 0 );
    
    /* Connect to the PCI server */
    phdl = pci_attach( 0 );
    if( phdl == -1 ) {
        fprintf( stderr, "Unable to initialize PCI\n" );

        return EXIT_FAILURE;
    }

    /* Initialize the pci_dev_info structure */
    memset( &inf, 0, sizeof( inf ) );
    pidx = 0;
    inf.VendorId = 0x10E3;
    inf.DeviceId = 0x0148;

    hdl = pci_attach_device( NULL, PCI_INIT_ALL, pidx, &inf );
    if( hdl == NULL ) {
        fprintf( stderr, "Unable to locate adapter\n" );
    } else {
        /* Do something to the adapter */
//    	pci_read_config( hdl , 0x10h, 1, 64);
        // reads base address from PCI configuration space
    	pci_read_config32( inf.BusNumber, inf.DevFunc, 0x10, 1, &pci_config_base_buffL);
    	pci_read_config32( inf.BusNumber, inf.DevFunc, 0x14, 1, &pci_config_base_buffH);

        // memory mapping test
        // void *memory_mapped = map_tsi148_registers(BASE_ADDR_CRG, CRG_SIZE);
        // if (!memory_mapped) {
        //     printf("Failed to map memory\n");
        //     return 1;
        // }
        // uint32_t *devi_veni = (uint32_t *)((uintptr_t)memory_mapped + DEVI_VENI_OFFSET)
        // uint32_t value = read_register(devi_veni);
        // printf("Read value from DEVI/VENI Register : 0x%08X\n", value);
        // unmap_tsi148_registers(memory_mapped, CRG_SIZE);

        pci_detach_device( hdl );
    }

    /* Disconnect from the PCI server */
    pci_detach( phdl );

    return EXIT_SUCCESS;
}
