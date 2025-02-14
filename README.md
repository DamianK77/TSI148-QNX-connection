## TSI148 PCI-VME bridge
### Features
- find and attach device
- map memory of device
- read and write registers

### Notes
- register ```64BCU``` is called in struct ```BCU64```
- register ```64BCL``` is called in struct ```BCL64```
- register ```VENI``` from group ```GCSR``` is called in struct ```VENI_2```
- register ```DEVI``` from group ```GCSR``` is called in struct ```DEVI_2```


### Functions

- ```read_TSI148_pci_config(uint64_t *pci_config_base_address, uint8_t *pci_interrupt_line)``` reads TSI148 PCI configuration, writes to pci_config_base_address and pci_interrupt_line
- ``` map_tsi148_registers(uint64_t base_address, size_t size)``` maps Tsi148 registers into virtual memory
-  ```TSI148_map_structure(uint8_t *error)``` maps virtual memory into structure of registers

### Read/Write oprerations
#### Write operation example
Writing value `0x00100000` to register ```OTAT0 ``` :\
```reginfo->OTAT0=0x00100000; ```
#### Read operation example
Reading from ```OTAT0 ``` register :\
```reginfo->OTAT0 ```
