#include<stdio.h>
#include<string.h>

typedef struct {
    char rno[15];
    char name[20];
    char branch[5];
    char selected[3];
}selection_list;

int main(){
    int N;
    int M = 0;
    int CSE = 0;
    printf("No.of Students: ");
    scanf("%d%*c",&N);

    selection_list list[N];
    for(int i = 0; i < N; i++){
        printf("Enter rno, name, branch, selected for %d\n",i+1);
        scanf("%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c",&list[i].rno, &list[i].name, &list[i].branch, &list[i].selected);
            
        //printf("%s",list[i].selected);
        if(strcmp(list[i].selected,"yes")==0){
            M++;
            //printf("%d",M);
        }

        if(strcmp(list[i].branch,"CSE")==0){
            CSE++;
        }
    }
    selection_list Non_CSE[N-CSE];
    selection_list CSE_list[CSE];
    selection_list list1[CSE];
    int j = 0, k = 0,l = 0;
    for(int i = 0; i < N; i++){
        if(strcmp(list[i].branch,"CSE")==0){
            CSE_list[j++] = list[i];
        }
        else{
            Non_CSE[l++] = list[i];
        }
        if((strcmp(list[i].branch,"CSE")==0) && (strcmp(list[i].selected,"Yes")==0 || strcmp(list[i].selected,"yes")==0)){
            list1[k++] = list[i];
        }
    }

    printf("No. of students selected for the interview: %d", M);
    printf("\n");

    printf("List of students who appeared from CSE Dept:\n");
    for(int i = 0; i<CSE; i++){
        printf("%s ",CSE_list[i].name);
    }
    printf("\n");

    printf("list of students selected from CSE Dept:\n");
    for(int i = 0; i<k; i++){
        printf("%s ",list1[i].name);
    }
    printf("\n");

    printf("list of students who are not from CSE Dept:\n");
    for(int i = 0; i<(N-CSE); i++){
        printf("%s ",Non_CSE[i].name);
    }
    printf("\n");

    return 0;
}