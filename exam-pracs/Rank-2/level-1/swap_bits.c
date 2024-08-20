/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100*/

 unsigned char swap_bits(unsigned char octet)
 {
	unsigned char upper = (octet & 0xF0);
	unsigned char lower = (octet & 0x0F);

	upper >>= 4;
	lower <<= 4;
	return (lower | upper);
 }