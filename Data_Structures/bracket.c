#include<stdio.h>
#include<stdbool.h>
#define MAX 50

typedef struct
{
    char bracket;
    int position;
}element;

element stack[MAX];
int top = -1;

void push(char x, int counter);
element pop();
bool isValid(char []);

void push(char x, int counter)
{
    stack[++top].bracket = x;
    stack[top].position = counter;
    return;
}

element pop()
{
    return stack[top--];    
}

bool isValid(char a[])
{
    element temp;
    //printf("%s",a);
    char *ptr = a;
    //printf("\n%c",*ptr);
    int counter = 0;
    while(*ptr!='\0')
    {
        //printf("\nIn while loop\n");
        if(*ptr=='('||*ptr=='{'||*ptr=='[')
        {
            push(*ptr,counter);
            ptr++;counter++;
        }
        else if(*ptr==')')
        {
            if(stack[top].bracket == '(')
            {
                temp = pop();
                printf("(%d,%d) ",temp.position,counter);
                ptr++;counter++;
            }
            else
            {
                return 0;
            }
        }
        else if(*ptr=='}')
        {
            if(stack[top].bracket == '{')
            {
                printf("(%d,%d),",stack[top].position,counter);
                temp = pop();
                ptr++;counter++;
            }
            else
            {
                return 0;
            }
        }
        else if(*ptr==']')
        {
            if(stack[top].bracket == '[')
            {
                printf("(%d,%d),",stack[top].position,counter);
                temp = pop();
                ptr++;counter++;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            ptr++;counter++;
        }
    }
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char stack[MAX];
    printf("Enter the string: ");
    scanf("%[^\n]%*c",stack);
    bool check = isValid(stack);
    printf("\n%s",check);
    return 0;
}