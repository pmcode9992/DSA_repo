#include<stdio.h>

void push(int stack[],int *top,int n){
    if(*top==n-1){
        printf("STACK IS FULL!!\n");
    }
    else{
        int e;
        printf("Enter element to enter : ");
        scanf("%d",&e);
        *top=*top+1;
        stack[*top]=e;
        printf("\n%d added to stack successfully!!\n",e);
    }
}
void pop(int stack[],int *top, int n){
    if(*top==-1){
        printf("STACK IS EMPTY!!\n");
    }
    else{
        *top=*top-1;
        printf("Element deleted successfully!!\n");
    }
}
void display(int stack[],int *top){
    printf("Stack elements are : ");
    for(int i=0;i<=*top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    int n,op=1,top=-1;
    printf("Menu driven program for STACK Array implementation\n");
    printf("Enter size of stack\n");
    scanf("%d",&n);
    int stack[n];
    while(op!=4){
        printf("Enter 1 : PUSH || 2 : POP || 3 : Display || 4 : Exit \n ");
        scanf("%d",&op);
        switch (op){
            case 1:
                push(stack,&top,n);
                break;
            case 2:
                pop(stack,&top,n);
                break;
            case 3:
                display(stack,&top);
                break;
            case 4:
                printf("Exit successful\n");
                break;
            default:
                printf("Incorrect input entered\n");
                break;
        }
    }
    return 0;
}