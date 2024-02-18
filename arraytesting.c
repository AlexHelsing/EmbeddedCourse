#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

int array[MAX]; 
int arrayLength = sizeof(array) - sizeof(array[0]);
int* ptrArrayLength = &arrayLength;

void generateRandomArray(int array[], int *size){
    int i;
    int num;
    for(i = 0; i < *size; i++){
        num = rand() % 100 + 1;
        array[i] = num;
    }
}

void printArrayDouble(int array[], int *size){
    int i;
    for(i = 0; i < *size; i++){
        printf("%d\n", array[i] * 2);
    }

}

int main(int argc, char const *argv[])
{
    /* code */

    srand(time(NULL));

    generateRandomArray(array, ptrArrayLength);

    printArrayDouble(array, ptrArrayLength);

    printf("%p", array);
    printf("\n");
    printf("%d", array[0]);
    printf("\n");
    printf("%d", array[MAX - 1]);
    printf("\n");
    printf("%lu", sizeof(int));
    printf("\n");
    printf("%lu", (sizeof(array) / sizeof(array[0])) * sizeof(int));


    return 0;
}
