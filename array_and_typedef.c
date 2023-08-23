#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Playing with operations between arrays and defined types */

typedef uint8_t response_data_t[8];

uint8_t array1[8] =  {1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u};

typedef struct {
   uint16_t something_else;
   response_data_t payload;
} isoResult_t;

isoResult_t isoResult;

int main()
{   
    uint8_t i;
    
    for(i = 0; i < 8; i++)
    {
        isoResult.payload[i] = array1[i];
    }
    /* isoResult->(&payload) = array1; */
    
    for(i = 0; i < 8; i++)
    {
        printf("%d\n", isoResult.payload[i]);
    }
    
    /*for(i = 0; i < sizeof(SubNodeActiveFaults_type); i++)
        memset(&activeFaults, array[i], sizeof(uint8_t));*/
        
    /*activeFaults += (isoResult[i+2] << (8*i));*/
    //printf("%d\n", (0xFF & (activeFaults << (8u*i))));
    //memcpy(&activeFaults, isoResult, sizeof(SubNodeActiveFaults_type));
    //memset(&activeFaults, isoResult.payload[2],sizeof(SubNodeActiveFaults_type));
    //memset(&activeFaults.numberOfActiveFaults, array, sizeof(uint16_t));
    /*printf("%d\n", sizeof(SubNodeActiveFaults_type));
    printf("%d\n", array[1]);
    printf("%ld\n", activeFaults);
    printf("%ld\n", &activeFaults);*/

    return 0;
}



