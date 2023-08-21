#include <stdio.h>
#include <stdint.h>

/* This code swaps endianess */

static uint16_t swapBigToLittleEndian(uint16_t num);
static uint16_t swapBigToLittleEndian(uint16_t num)
{
	uint16_t swapped = (num>>8) | (num<<8);
	return swapped;
}

int main()
{   
    uint16_t unsigned_v = 32000;
    int16_t signed_v;
    
    signed_v = (int16_t)unsigned_v;
    
    printf("Value unsigned: %d\n", unsigned_v);
    printf("Value signed: %d\n", signed_v);

    /* Swap endianess */
    printf("Value unsigned swaped: %d\n", swapBigToLittleEndian(unsigned_v));
    printf("Value signed swaped: %d\n", swapBigToLittleEndian(signed_v));
    
    return 0;
}

