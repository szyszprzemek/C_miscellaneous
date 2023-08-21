#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

uint16_t value1 = 0xFFFE;
uint16_t value2 = 0xFEFC;
uint16_t value3 = 0xF5B2;
uint16_t value4 = 0xD638;

/* This code checks for two compl value */

int main()
{
    int16_t result1, result2, result3, result4;
    
    memcpy(&result1, &value1, sizeof(value1));
    memcpy(&result2, &value2, sizeof(value2));
    memcpy(&result3, &value3, sizeof(value3));
    memcpy(&result4, &value4, sizeof(value4));
    
    printf("For %d two compl: %d\n", value1, result1/32);
    printf("For %d two compl: %d\n", value2, result2/32);
    printf("For %d two compl: %d\n", value3, result3/32);
    printf("For %d two compl: %d\n", value4, result4/32);
    
    return 0;
}


