#include<stdio.h>
#include<math.h>

typedef struct
{
	int x;
    int y;
}point;

void SelectionSort(point [],int n);

void SelectionSort(point a[],int n)
{
    int min_index;
    point t;
    for(int j = 0; j < n-1; j++)
    {
        min_index = j;
        for(int i = j + 1; i < n; i++)
        {
            if(a[i].x<a[min_index].x)
            {
                min_index = i;
            }
        }
        if(min_index!=j)
        {
            t = a[min_index];
            a[min_index] = a[j];
            a[j] = t;    
        }
    }
    return;
}

int main()
{
	int N;
    int X;
    scanf("%d",&N);
    point points[N];
    for(int i = 0; i < N; i++)
    {
    	scanf("%d%d",&points[i].x,&points[i].y);
	}
    SelectionSort(points,N);    

    // printf("The points in sorted order:\n");
    // for(int i = 0; i < N; i++)
    // {
    //     printf("%d %d\n",points[i].x,points[i].y);
    // }
    X = points[0].x;
    point min[N];
    min[0] = points[0];
    int j = 0;
    int count = 1;
    for(int i = 0; i<N; i++)
    {
    	if(points[i].x == X)
        {
        	if(min[j].y > points[i].y)
            {
            	min[j] = points[i];
            }
        }
        else
        {
        	count++;
        	j++;
            X = points[i].x;
        }
	}
    
    float perimeter;
    
	for(int i = 0; i < count-1; i++)
    {
    	perimeter = sqrt((min[i+1].x - min[i].x)^2 + (min[i+1].y - min[i].y)^2);
    }
    int Perimeter = roundf(perimeter);  
    printf("%d",Perimeter);
    return 0;
}