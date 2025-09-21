#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef struct
{
    char element;
}Stack;

Stack stack[MAXSIZE];
int top = -1;

void push(char x);
bool isfull();
bool isempty();
char pop();
char view();

bool isValid(char* s);

void push(char x)
{
    if(isfull()){
        printf("Can't push, stack full");
        return;
    }
    else{        
        stack[++top].element = x;
    }
    return;
}

char pop()
{
    if(isempty()){
        printf("Can't pop, stack empty");
        return 'N';
    }
    else{        
        return stack[top--].element; 
    }
}

char view()
{
    return stack[top].element;
}

bool isfull()
{
    if(top==(MAXSIZE-1))
    {
        return true;
    }
    return false;
}

bool isempty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

bool isValid(char* s) 
{
    int length = strlen(s);
    char arr[length];
    int j = 0;
    for(int i = 0; i < length; i++)
    {
        //printf("%c",*(s+i));
        if(*(s+i)=='('||*(s+i)=='{'||*(s+i)=='[')
        {
        //    printf("in if %d\n", i);
            push(*(s+i));
        }
        else
        {
            switch(pop())
            {
                case '}':
                    if(view()=='{')
                    {
                    //    printf("in case 1\n");
                        top--;
                    }
                    else
                    {
                    //    printf("in else case 1\n");
                        return false;
                    }
                    break;
                case ')':
                    if(view()=='(')
                    {
                    //    printf("in case 2\n");
                        top--;
                    }
                    else
                    {
                    //    printf("in else case 2\n");
                        return false;
                    }
                    break;
                case ']':
                    if(view() == '[')
                    {
                        top--;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    return false;
            }    
        }
    }
    if(isempty())
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d",&n);
    char word[n];
    scanf("%*c%[^\n]%*c",word);
    //printf("%d\n",strlen(word));
    //int length = sizeof(word)/sizeof(word[0]);
    //printf("%d",length);
    printf("%d",isValid(word));
    return 0;
}