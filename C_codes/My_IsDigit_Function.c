#include <stdio.h>

int ifdigit (char a);

int main()
{
    int b;
    char a;
    printf("Enter a single digit character : ");
    scanf("%c",&a);
    
    b = ifdigit (a);
    
    if(b==1)
    {
        printf("The entered character is a number");
    }
    else
    {
        printf("The entered character is not a number");
    }
    
    return 0;
}

int ifdigit(char a)
{
    int ascii = (int)a;
    if( 48 <= ascii && ascii <= 57)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}