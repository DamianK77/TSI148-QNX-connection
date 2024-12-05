#ifndef TSI_STRUCT_H
#define TSI_STRUCT_H

#include <sys/mman.h>
#include <sys/neutrino.h>
#include <stdint.h>
#include <stdio.h>
#include <errno.h>

#define BASE_ADDR_CRG 0x0101 // change later to proper address
#define CRG_SIZE 0x1000 // 4 Kbyte size 

// -----------------------------
// Memory Mapping Functions
// -----------------------------

/**
 * @brief Map Tsi148 registers into virtual memory.
 * 
 * @param base_address The physical base address of the register group.
 * @param size The size of the memory region to map.
 * @return void* Pointer to the mapped virtual memory, or NULL on failure.
 */
static inline void* map_tsi148_registers(uint64_t base_address, size_t size) {
    // Ensure the thread has I/O privileges
    if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1) {
        perror("ThreadCtl failed");
        return NULL;
    }

    // Map the physical memory
    void *mapped_base = mmap_device_memory(
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

// -----------------------------
// Read/Write Utility Functions
// -----------------------------

/**
 * @brief Read a 32-bit value from a mapped register.
 * 
 * @param addr Address of the register to read.
 * @return uint32_t Value read from the register.
 */
static inline uint32_t read_register(uint32_t *addr) {
    return *addr;
}

/**
 * @brief Write a 32-bit value to a mapped register.
 * 
 * @param addr Address of the register to write.
 * @param value Value to write to the register.
 */
static inline void write_register(uint32_t *addr, uint32_t value) {
    *addr = value;
}

// -----------------------------
// Registers offsets from CRG
// -----------------------------
#define DEVI_VENI_OFFSET 0x000
#define STAT_SMMD_OFFSET 0x004
#define CLAS_REVI_OFFSET 0x008
#define HEAD_MLAT_CLSZ_OFFSET 0x00C
#define MBAR_OFFSET 0x010
#define MBARU_OFFSET 0x014
// add more offsets

#endif // TSI_STRUCT_H
