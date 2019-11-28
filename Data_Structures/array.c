
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n\n");
    printf("Array Data Structure \n");
    printf("Initalize an array with 5 spaces.\n\n");

    int n = 5;
    int array[n];

    for (int i = 0; i < n; i++)
    {
         array[i] = i;
        printf("%d ", array[i]);
    }

    printf("\n\n");

    printf("Insertion: When inserting an element into an array. \n");
    printf("We would need to iterate throught the array till the first empty spot is found. \n");

    return 0;
}
