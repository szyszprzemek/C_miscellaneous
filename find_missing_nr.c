#include <stdio.h>

/* This program finds smallest number missing in the given array. 
 * But not smaller than 1.
 */
 
int A1[] = {1, 3, 6, 4, 1, 2};
int A2[] = {1, 2, 3};
int A3[] = {-1, -3};

int solution(int A[], int N) 
{
    int i;
    int ret = 1;
    
    for (i = 0; i < N; i++)
    {
        if (ret == A[i])
        {
            ret++;
            i = 0;
        }            
    }
    
    return ret;
}

int main()
{
    printf("Result A1: %d\n", solution(A1, sizeof(A1) / sizeof(A1[0])));
    printf("Result A2: %d\n", solution(A2, sizeof(A2) / sizeof(A2[0])));
    printf("Result A3: %d\n", solution(A3, sizeof(A3) / sizeof(A3[0])));
    
    return 0;
}
