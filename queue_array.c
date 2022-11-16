#include<stdio.h>

void push(int queue[],int *rear,int *front,int n,int *size){
    if(*front==-1 && *rear==-1){
       *front=0;
       *rear=0;
    }
    if(*size >= n){
        printf("Queue is full\n");
    }
    else{
        int e;
        printf("\nEnter element to insert : ");
        scanf("%d",&e);
        queue[*rear]=e;
        *rear=(*rear+1)%n;
        *size  = *size + 1;

    }
}
void pop(int queue[],int *front,int rear, int n,int *size){
    if(*size==0){
        printf("Queue is empty!!\n");
    }
    else{
        printf("%d popped",queue[*front]);
        *front = (*front + 1)%n;
        *size = *size - 1 ;

    }
}
void display(int queue[],int front, int rear,int n,int size){
    printf("Queue elements are\n");
    int c=0,i=front;
    while(c!=size){
        printf("%d ",queue[i]);
        i=(i+1)%n;
        c++;
    }
    
}
int main()
{
    int n,op=1,front=-1,rear=-1,size=0;
    printf("Enter size of queue : ");
    scanf("%d",&n);
    int queue[n];
    while(op!=4){
        printf("\nEnter 1 : PUSH || 2 : POP || 3 : Display || 4 : Exit \n ");
        scanf("%d",&op);
        switch (op){
            case 1:
                push(queue,&rear,&front,n,&size);
                break;
            case 2:
                pop(queue,&front,rear,n,&size);
                break;
            case 3:
                display(queue,front,rear,n,size);
                break;
            case 4:
                printf("Exit successful\n");
                break;
            default:
                printf("Incorrect input entered\n");
                break;
        }
    }
    
}