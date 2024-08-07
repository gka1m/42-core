unsigned char swap_bits(unsigned char octet)
{
	unsigned char lower = octet & 0x0F;
	unsigned char upper = octet & 0xF0;

	lower <<= 4;
	upper >>= 4;
	return (lower | upper);
}
