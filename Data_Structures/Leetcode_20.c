#include<stdio.h>
#include<stdbool.h>

bool isValid(char* s);

bool isValid(char* s) 
{
    // printf("%d\n",sizeof(s));
    // printf("%d\n",sizeof(char));
    int length = sizeof(s) / sizeof(char);
    //printf("%d",length);
    char arr[length];
    int j = 0;
    for(int i = 0; i < length; i++)
    {
        if(*(s+i)=='('||*(s+i)=='{'||*(s+i)=='[')
        {
            arr[j++] = *(s+i);
        }
        else
        {
            switch(*(s+i))
            {
                case '}':
                    if(arr[--j] == '{')
                    {
                        j--;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ')':
                    if(arr[--j] == '(')
                    {
                        j--;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if(arr[--j] == '[')
                    {
                        j--;
                    }
                    else
                    {
                        return false;
                    }
                    break;
            }    
        }
    }
    if(sizeof(*s)!=0)
    {
        return false;
    }
    return true;
}

int main()
{
    char s[] = "{[()]}";
    bool valid = isValid(s);
    printf("%s",valid);
}