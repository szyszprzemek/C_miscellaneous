#include <stdio.h>
#include <stdint.h>

/* Code to test __may_alias__ attribute */

/* Types, enums, function declarations */
typedef enum {
    FIRST_STATUS_INITIALIZING = 0,
    FIRST_STATUS_STANDBY = 1,
    FIRST_STATUS_ENABLING = 2,
    FIRST_STATUS_ENABLED = 3,
    FIRST_STATUS_DISABLING = 4,
    FIRST_STATUS_AFTERRUN = 5,
    FIRST_STATUS_ERROR = 6,
    FIRST_STATUS_STAND_ALONE = 13,
    FIRST_STATUS_ERROR_INDICATOR = 14,
    FIRST_STATUS_NOT_AVAILABLE = 15,
    FIRST_STATUS_LAST 
} FIRST_STATUS;

typedef enum {
    SECOND_STATUS_INITIALIZING = 0,
    SECOND_STATUS_STANDBY = 1,
    SECOND_STATUS_ENABLING = 2,
    SECOND_STATUS_ENABLED = 3,
    SECOND_STATUS_DISABLING = 4,
    SECOND_STATUS_AFTERRUN = 5,
    SECOND_STATUS_ERROR = 6,
    SECOND_STATUS_STANDBYLOWPOWER = 7,
    SECOND_STATUS_ERRORLOWPOWER = 8,
    SECOND_STATUS_INVALID = 9,
    SECOND_STATUS_STAND_ALONE = 13,
    SECOND_STATUS_ERROR_INDICATOR = 14,
    SECOND_STATUS_NOT_AVAILABLE = 15,
    SECOND_STATUS_LAST 
} SECOND_STATUS;

//typedef uint8_t __attribute__((__may_alias__)) STATUS;
typedef void (*Status_Set_funp)(uint8_t *value);

//typedef Status_Setd_funp __attribute__((__may_alias__)) new_func;
//typedef Status_Setb_funp __attribute__((__may_alias__)) new_func;

typedef struct {
    uint8_t id;
    Status_Set_funp Status_Set;
} subNode;

void ActualStatusD1_Set(FIRST_STATUS * value);
void ActualStatusB1_Set(SECOND_STATUS * value);

/* Globals */
uint8_t v;
subNode subNodeArray[2];

int main (void)
{
    /* Init */
    subNodeArray[0].id = 0;
    subNodeArray[0].Status_Set = &ActualStatusD1_Set;
    subNodeArray[1].id = 1;
    subNodeArray[1].Status_Set = &ActualStatusB1_Set;
    
    /* Tests */
    FIRST_STATUS d1;
    SECOND_STATUS b1;
    d1 = FIRST_STATUS_STANDBY;
    b1 = SECOND_STATUS_ERROR;
    
    subNodeArray[0].Status_Set(&d1);
    printf("Value for id %d is: %d\n", subNodeArray[0].id, v);
    subNodeArray[1].Status_Set(&b1);
    printf("Value for id %d is: %d\n", subNodeArray[1].id, v);
    return 0; 
} 


/* Local functions */
void ActualStatusD1_Set(FIRST_STATUS * value)
{
    v = (uint8_t)(*value);
}

void ActualStatusB1_Set(SECOND_STATUS * value)
{
    v = (uint8_t)(*value);
}
