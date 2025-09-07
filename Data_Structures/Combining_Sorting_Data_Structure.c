#include<stdio.h>

typedef struct
{
    char name[20];      //each item of list
    char roll_no[30];
    float marks;
}Student_List;              

void Bubble_Sort(Student_List [], int n);

void Bubble_Sort(Student_List a[], int n)
{
    int i,j;
    float temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j].marks>a[j+1].marks)
            {
                temp = a[j].marks;
                a[j].marks = a[j+1].marks;
                a[j+1].marks = temp;
            }
        }
    }
    return;
}

int main()
{
    int nA,nB,temp;
    int i,j,k;
    printf("Enter the number of students in CSE A: ");
    scanf("%d",&nA);
    printf("Enter the number of students in CSE B: ");
    scanf("%d",&nB);

    Student_List CSE_A[nA];
    Student_List CSE_B[nB];
    Student_List CSE[nA+nB];

    printf("\nEnter CSE A student details: ");
    for(i = 0; i < nA; i++)
    {
        printf("Student %d\n",i+1);
        printf("Name: ");
        scanf("%*c%[^\n]%*c",&CSE_A[i].name);
        printf("Roll No: ");
        scanf("%[^\n]%*c",&CSE_A[i].roll_no);
        printf("Marks: ");
        scanf("%f",&CSE_A[i].marks);
        printf("\n");
    }

    printf("Enter CSE B student details: ");
    for(i = 0; i < nB; i++)
    {
        printf("Student %d\n",i+1);
        printf("Name: ");
        scanf("%*c%[^\n]%*c",&CSE_B[i].name);
        printf("Roll No: ");
        scanf("%[^\n]%*c",&CSE_B[i].roll_no);
        printf("Marks: ");
        scanf("%f",&CSE_B[i].marks);
        printf("\n");
    }

    Bubble_Sort(CSE_A,nA);
    Bubble_Sort(CSE_B,nB);

    k = 0;
    i = 0, j = 0;
    while((i < nA)||(j < nB))
    {
        if(CSE_A[i].marks>CSE_B[j].marks)
        {
            CSE[k++] = CSE_B[j++];
            //printf("In if %.1f\n",CSE[k].marks);
        }
        
        else
        {
            CSE[k++] = CSE_A[i++];
            //printf("In else %.1f\n",CSE[k].marks);
        }
    }
    
    if(i!=(nA-1))
    {
        for(; i < nA; i++)
        {
            CSE[k++] = CSE_A[i];
        }
    }
    
    else if(j!=(nB-1))
    {
        for(; j < nB; j++)
        {
            CSE[k++] = CSE_B[j];
        }
    }

    printf("The final list of CSE students: \n");
    for(i = 0; i < (nA+nB); i++)
    {
        printf("%s\t%s\t%.1f\n",CSE[i].name,CSE[i].roll_no,CSE[i].marks);
        //printf("%.1f\n",CSE[i].marks);
    }
    return 0;
}