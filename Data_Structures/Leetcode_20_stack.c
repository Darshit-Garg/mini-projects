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
void view();
void clear();

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

void view()  //This function is just there to check the state of stack at any time
{
    if(top==-1)
    {
        printf("Empty");
    }
    for(int i = 0; i <= top; i++)
    {
        printf("%c ",stack[i].element);
        
    }
    printf("\n");
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

void clear()
{
    top = -1;
}

bool isValid(char* s) 
{
    int length = strlen(s);
    clear();
    //view();
    for(int i = 0; i < length; i++)
    {
        if((*(s+i)=='(')||(*(s+i)=='{')||(*(s+i)=='['))
        {
            push(*(s+i));
            //view();
        }
        else
        {
            switch(*(s+i))
            {
                case '}':
                    if((top!=-1) && (stack[top].element=='{'))
                    {
                        top--;
                        //view();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ')':
                    if((top!=-1) && (stack[top].element=='('))
                    {
                        top--;
                        //view();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if((top!=-1) && (stack[top].element=='['))
                    {
                        top--;
                        //view();
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
    if(isValid(word))
    {
        printf("true\n");
    }
    else
    {
        printf("false"\n);
    }
    return 0;
}
