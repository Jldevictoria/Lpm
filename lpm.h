/* 
 * Lightweight Pcimem Library
 * Made by Joseph DeVictoria (2014)
 * Based off pcimem by Bill Farrow
 * License: GNU General Public License V2
 */

#ifndef __LPM_H__
#define __LPM_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>

#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

// Internal pci card structure for working with file descriptor/memory space.
struct pci_card{
	int fd;
	void *map_base, *virt_addr;
	unsigned long read_result, writeval;
	char *filename;
	off_t target;
};

// Initialization function called within read and write functions.
void pci_card_init(struct pci_card *card);

// Takes in the desired card's filename, and the desired address, and returns the memory contents.
unsigned long pci_card_read(char* fname, char* raddr);

// Takes in the desired card's filename and input value, and writes it to the desired address.
void pci_card_write(char* fname, char* raddr, unsigned long wval);

#endif


