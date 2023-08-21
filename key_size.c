#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* This program checks different sizes of pointers and a struct holding the key */

typedef struct
{
   uint32_t* cipherKey_p;
}meta_locals_blockDefinition_t;

uint32_t data[] = {1,2,3,4};

int main()
{   
    printf("Sizeof data: %d\n", sizeof(data));
    meta_locals_blockDefinition_t meta_blocks;
    meta_blocks.cipherKey_p = data;
    printf("Sizeof pointer: %d\n", sizeof(*(meta_blocks.cipherKey_p)));
    printf("Sizeof pointer: %d\n", sizeof(meta_blocks.cipherKey_p));
    printf("Sizeof data: %d\n", sizeof(uint32_t));

    return 0;
}


