#include <stdio.h>
#include <stdint.h>

/* This program test __may_alias__ with unions */

/* Types, enum, function declarations */
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

typedef uint8_t __attribute__((__may_alias__)) STATUS;
typedef void (*Status_Set_funp)(uint8_t *value);
typedef void (*Status_Setd_funp)(FIRST_STATUS *value);
typedef void (*Status_Setb_funp)(SECOND_STATUS *value);

typedef union {
  void (*Status_Set_funp)(uint8_t *value);
  void (*Status_Setd_funp)(FIRST_STATUS *value);
  void (*Status_Setb_funp)(SECOND_STATUS *value);
} func_all;

//typedef Status_Setd_funp __attribute__((__may_alias__)) new_func;
//typedef Status_Setb_funp __attribute__((__may_alias__)) new_func;

typedef struct {
    uint8_t id;
    func_all Status_Set;
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
    subNodeArray[0].Status_Set.Status_Setd_funp = &ActualStatusD1_Set;
    subNodeArray[1].id = 1;
    subNodeArray[1].Status_Set.Status_Setb_funp = &ActualStatusB1_Set;
    
    /* Tests */
    FIRST_STATUS d1;
    SECOND_STATUS b1;
    d1 = FIRST_STATUS_STANDBY;
    b1 = SECOND_STATUS_ERROR;
    
    subNodeArray[0].Status_Set.Status_Setd_funp(&d1);
    printf("Value for id %d is: %d\n", subNodeArray[0].id, v);
    subNodeArray[1].Status_Set.Status_Setb_funp(&b1);
    printf("Value for id %d is: %d\n", subNodeArray[1].id, v);
    /* sizeof */
    printf("Size of funcp with uint8_t is: %d\n", sizeof(Status_Set_funp));
    printf("Size for id %d is: %d\n", subNodeArray[0].id, sizeof(Status_Setd_funp));
    printf("Size for id %d is: %d\n", subNodeArray[1].id, sizeof(Status_Setb_funp));
    printf("Size of funcall with uint8_t is: %d\n", sizeof(func_all));
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
