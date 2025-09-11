#include<stdio.h>
#include<stdlib.h>
int x,n;
void store(int a[],int r,int c);
int retreive(int a[],int r,int c);
int main()
{
	int *a,i,j,ans;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("Enter the element %d %d\n",i,j);
			scanf("%d",&x);
			store(a,i,j);
		}
	}
	printf("Contents of the matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ans=retreive(a,i,j);
			if(ans == 1)
			{
				printf("%d\t",x);
			}
		}
		printf("\n");
	}
	return 0;
}
void store(int a[],int r,int c)
{
	if(r<0 || r>n || c<0 || c>n)
	{
		printf("Invalid position\n");
		return;
	}
	  if(r!=c && x!=0)
		{
			printf("Invalid element\n");
			return;
		}
	   else
		{
			if(r == c)
			{
				a[r-1]=x;
			}
		}
	   return;
}
int retreive(int a[],int r,int c)
{
	if(r<1 || r>n || c<1 || c>n)
	{
		printf("Invalid position\n");
		return 0;
	}
	else
	{
		if(r!=c)
		{
                   x=0;
		   return 1;
		}
		else
		{
			x=a[r-1];
			return 1;
		}
	}
}
