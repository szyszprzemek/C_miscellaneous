#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* Memcmp tests */

typedef struct {
    uint8_t a;
    uint16_t b;
    uint8_t c[5];
} testType;

int main()
{   
    testType test;
    testType test2 = {0};
    test.a = 6;
    test.b = 7;
    
    //memset(&test2, 0u , sizeof(test));
    
    printf("Hello World: %d \n", test.a);
    printf("%d \n", memcmp(&test, &test2, sizeof(test)));
    memset(&test, 0u , sizeof(test));
    printf("%d \n", memcmp(&test, &test2, sizeof(test)));
    printf("Hello World: %d \n", test.a);
    

    return 0;
}
