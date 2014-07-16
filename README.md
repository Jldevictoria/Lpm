lpm - Lightweight PCIe Memory Library
===

 * Lightweight Pcimem Library
 * Made by Joseph DeVictoria (2014)
 * <jldevictoria@gmail.com>
 * Based off pcimem by Bill Farrow
 * License: GNU General Public License V2

This library is designed to allow the user to access memory registers on PCI (express) devices.

===

The functions ( pci_card_read() and pci_card_write() ) contained require the user to supply a filename for opening the device file descriptor as a char* in the form:

 * "/sys/bus/pci/devices/0000:0X:00.0/resource5"

 or more generally:

 * "/sys/bus/pci/devices/[DOMAIN]:[BUS]:[SLOT].[FUNCTION]/resource[BAR]"

===

Additionally both of the aforementioned functions require a register offset (from the selected BAR) in the form:

 * "0xXXXX" where X = hex value. (Ex: 0x9381)

===

Finally, the pce_card_write() function requires an eight byte value to write into the pci memory register at the specified address.  This should be of the form:

 * "0xXXXXXXXX" where X = hex value. (Ex: 0xDEADBEEF)

