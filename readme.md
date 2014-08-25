lpm - Lightweight PCIe Memory Library
===

 * Lightweight Pci-Memory Module Library
 * Made by Joseph DeVictoria (2014)
 * <jldevictoria@gmail.com>
 * Based off "pcimem" by Bill Farrow
 * License: GNU General Public License V2

===

 * This library is designed to allow the user to access memory registers on PCI (express) devices.
 * This library is meant to be compiled as position independent code.
 * A makefile has been included to facilitate this process.

===

The function ( pci_card_init() ) takes in a filename of the form (X are variables):

 * "/sys/bus/pci/devices/0000:0X:00.0/resourceX"  (Usually recource5)

It also takes in a register address within the specific pci card that you want to be reading and writing to.

The return value is a struct pointer that behaves like a link to a specific register on a pci-express card.

===

The functions ( pci_card_read(), pci_card_write(), and free_pci_card()  ) require a pci_card struct pointer.

 * The read function simply returns the value stored at that register.
 * The write function will take in an unsigned value and write it to the register.
 * The free function will free up the memory used in making the pci_card struct.

===

A rough example of how I would use this library within my c code is shown below:

    #include "lpm.h"

    int main(){
        char *address;
        unsigned long register;
        struct pci_card *dummy;
        unsigned rVal, wVal;

        address = "/sys/bus/pci/devices/0000:08:00.0/resource5";
        register = 0x8004;
        dummy = pci_card_init(address, register);

        rVal = pci_card_read(dummy);

        wVal = 0xDEADBEEF;
        pci_card_write(dummy, wVal);

        free_pci_card(dummy);
    }
