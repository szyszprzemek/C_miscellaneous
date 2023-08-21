#include <stdio.h>
#include <stdbool.h>

/* This program count how many even adjacent pairs are there in the given array.
 * Used number cannot be used to create another pair
 */

int A1[] = {4, 2, 5, 8, 7, 3, 7};
int A2[] = {14, 21, 16, 35, 22};
int A3[] = {5, 5, 5, 5, 5, 5};

int solution(int A[], int N)
{  
    int i, nr = 0;
    bool checkBothEnds = true;

    /* Iterate through the array elements */
    for (i = 0; i < N - 1; i++)
    {  
        /* If adjacent elements are even then increase the number */
        if (0 == ((A[i] + A[i + 1]) % 2))
        {
            /* Increase number */
            nr++;
            i = i + 2;

            /* Check if the endings were used and if they were, dont check them again */
            if ((i == 0) || (i == N - 2))
            {
                checkBothEnds = false;
            }
        }
    }

    /* Check special case, both ends if they werent yet used */
    if (true == checkBothEnds)
    {
        /* If sum of endings is even then increase the number */
        if (0 == ((A[0] + A[N - 1]) % 2))
        {
            nr++;
        }
    }

    return nr;

}

int main()
{
    printf("A1 has: %d\n", solution(A1, sizeof(A1) / sizeof(A1[0])));
    printf("A2 has: %d\n", solution(A2, sizeof(A2) / sizeof(A2[0])));
    printf("A3 has: %d\n", solution(A3, sizeof(A3) / sizeof(A3[0])));

    return 0;
}
