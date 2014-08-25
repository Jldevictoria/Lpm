/*
 * Lightweight Pci-Memory Module Library
 * Made by Joseph DeVictoria (2014)
 * Based off "pcimem" by Bill Farrow
 * License: GNU General Public License V2
 */

#include "lpm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pci_card *pci_card_init(char *filename, unsigned long raddr){
    struct pci_card *device = (struct pci_card *) malloc(sizeof(struct pci_card));
    device->fd = open(filename, O_RDWR | O_SYNC);
	device->target = (off_t)raddr;
	device->map_base = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, device->fd, device->target & ~MAP_MASK);
	device->virt_addr = device->map_base + (device->target & MAP_MASK);
    device->filename = filename;
	return device;
}

unsigned pci_card_read(struct pci_card *device){
    device->read_result = *((unsigned *) device->virt_addr);
	return device->read_result;
}

void pci_card_write(struct pci_card *device, unsigned wVal){
    *((unsigned *) device->virt_addr) = wVal;
	return;
}

void free_pci_card(struct pci_card *device){
    free(device);
}
