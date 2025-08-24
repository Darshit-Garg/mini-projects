#include<stdio.h>
int GlobalVar = 1;

int fibonacci(int x, int y, int limit) {
    int t;
    t = y;
    y = x+y;
    x = t;
    if (y<=limit) {
        printf("%d\n",y);
        return fibonacci(x,y,limit);
    }
    else {
        return 0;
    }
}

int main() {
    int x = 1;
    int y = 1;
    int limit;
    printf("Enter limit: ");
    scanf("%d",&limit);
    printf("%d\n",x);
    printf("%d\n",y);
    int j = fibonacci(x, y, limit);
    printf("Thanks");
}