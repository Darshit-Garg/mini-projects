#include<stdio.h>
#include<stdlib.h>

int **make2dArray(int rows, int cols);

int main()
{
    int **myArray;
    myArray = make2dArray(5,10);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d\t",myArray[i][j]);
        }
        printf("\n");
    }
}

int **make2dArray(int rows, int cols)
{
    int **x, i;
    x = (int **)calloc(rows,sizeof(*x));
    for(i = 0; i < rows; i++)
    {
        x[i] = (int *)calloc(cols,sizeof(**x));
    }
    return x;
}