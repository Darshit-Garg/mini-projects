#include<stdio.h>
#define MAXSIZE 1000

typedef struct linked_list{
    int info;
    int *next;
}lle;

typedef struct l_l{
    lle elements[MAXSIZE];
}ll;

// int pop(ll list, int *ptr);

// int pop(ll list, int *ptr) {
    
// }

int main() {
    int *p;
    int *q;
    q = NULL;

    ll MyList;
    for(int i = 0; i < 999; i++) { 
        if(i%4!=0) {
            MyList.elements[i].info = i;
        }
        else {
            MyList.elements[i].info = 4;  
        }
        MyList.elements[i].next = &(MyList.elements[i].info);
    }
    MyList.elements[999].info = 999;
    MyList.elements[999].next = NULL;

    int *list = &(MyList.elements[0].info);
    p = list;
    for(int i = 0; i < 1000; i++) { 
        printf("%d\n",*(MyList.elements[i].next));
    }

    // while(p!=NULL) {
    //     if(*p==4) { 
    //         if(q==NULL) {

    //         }
    //     }
    // }

}