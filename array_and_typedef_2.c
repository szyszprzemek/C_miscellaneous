
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Playing with operations between arrays and defined types */

typedef uint8_t response_data_t[4];

typedef struct
{
   response_data_t   payload;
}isoResult_t;

uint8_t payload[4] = {1, 2, 3, 4};

int main()
{
    uint16_t temp[2];
    isoResult_t isoResult;
    memcpy(isoResult.payload, payload, sizeof(payload));
    
    printf("size: %d \n", sizeof(uint16_t));
    printf("size: %d \n", sizeof(temp));
    
    memcpy(temp, &payload, sizeof(temp));
    printf("value [0]: %d \n", temp[0]);
    printf("value [1]: %d \n", temp[1]);
    
    
    printf("element number 2: %d \n", payload[2]);
    //printf("element number 2: %d \n", *payload[2]);
    printf("element number 2: %d \n", &(isoResult.payload[2]));
    printf("element number 2: %d \n", isoResult.payload);
    return 0;
}
