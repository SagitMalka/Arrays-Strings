/**
 * INSERTION SORT
 *
 * use pointers only, execlude declerintion
 * this program handels specific case of 50 inteegers only
 */

#include <stdio.h>

#define SIZE_OF_ARRAY 50

/**
    @brief shifts i elements by one to right
    @param arr pointer to some place in array
    @param i number of elements to shift
 */
void shift_element(int *arr, int i)
{
    int n;
    for (n = i - 1; n >= 0; n--)
    {
        *(arr + n + 1) = *(arr + n);
    }
}

/**
    @brief insertion sort use help function shift_elements
    @param arr pointer to array
    @param len length of array
*/
void insertion_sort(int *arr, int len)
{
    int i, j;
    for (i = 1; i < len; i++)
    {
        int key = *(arr + i);
        for (j = i - 1; j >= 0; j--)
        {
            if (*(arr + j) > key)
            {
                shift_element(arr + j, 1);
            }
            else
            {
                break;
            }
        }
        *(arr + j + 1) = key;
    }
}

int main()
{

    int array[SIZE_OF_ARRAY];
    for (int i = 0; i < SIZE_OF_ARRAY; i++)
    {
        scanf("%d", array + i);
    }
    insertion_sort(array, SIZE_OF_ARRAY);
    for (int i = 0; i < SIZE_OF_ARRAY - 1; i++)
    {
        printf("%d,", array[i]);
    }
    printf("%d\n", array[SIZE_OF_ARRAY - 1]);
    return 0;
}
