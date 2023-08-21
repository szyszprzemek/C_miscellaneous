#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* This code checks for two compl value and converts it */

uint16_t value1 = 0x104;
uint16_t value2 = 0xFEFC;
uint16_t value3 = 0xF5B2;
uint16_t value4 = 0xD638;

bool isTwoCompl(uint16_t value){
    return (0x8000 & value);
}

uint16_t removeMSB(uint16_t value){
    return (0x7FFF & value);
}

int16_t converter(uint16_t value){
    int16_t result;
    
    if(isTwoCompl(value))
    {
        result = (int16_t)(removeMSB(~value)/32);
    }
    else
    {
        result = (int16_t)(value/32);
    }
    return result;
}

int main()
{   
    int16_t result1, result2, result3, result4;
    
    printf("Is %d two compl: %d\n", value1, isTwoCompl(value1));
    printf("Is %d two compl: %d\n", value2, isTwoCompl(value2));
    printf("Is %d two compl: %d\n", value3, isTwoCompl(value3));
    printf("Is %d two compl: %d\n", value4, isTwoCompl(value4));

    printf("Is %d two compl: %d\n", value1, converter(value1));
    printf("Is %d two compl: %d\n", value2, converter(value2));
    printf("Is %d two compl: %d\n", value3, converter(value3));
    printf("Is %d two compl: %d\n", value4, converter(value4));
    return 0;
}

