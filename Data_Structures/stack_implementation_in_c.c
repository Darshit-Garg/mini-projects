#include <stdio.h>
#define STACKSIZE 100
#define INT 1
#define FLOAT 2
#define STRING 3
int empty(struct stack *ps);
struct stackelement {
    int etype;
    union {
        int ival;
        float fval;
        char *pval;
    }element;
};
struct stack {
    int top = -1;
    struct stackelement items[STACKSIZE];
    
};
int empty(struct stack *ps){
    if(ps->top==(-1)) {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    struct stack s;
    struct stackelement se;
    int check;
    check = empty(&s);
    for(int i = 0; i < 10; i++) {
        (s.items[i]).element.ival = i;
        s.top = i;
    }
    if (check==1) {
        printf('Stack is empty, cant perform the operation')
    }
    else {
        se.element.ival = (s.items[s.top]).element.ival;
        printf("%d",se.element.ival);
        switch(se.etype) { 
            case INT: printf("%d\n",se.element.ival);
            case FLOAT: printf("%f\n",se.element.fval);
            case STRING: printf("%s\n",se.element.pval);
        }
    }
    return 0;
}