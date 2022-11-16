#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void push(int *size,int n){
    if(*size ==n){
        printf("Queue is full\n");
    }
    else if (*size ==0){
        int e;
        printf("Enter element to be inserted\n");
        scanf("%d",&e);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data=e;
        newnode->next=NULL;
        rear=newnode;
        front = newnode;
        *size = *size +1;
    }
    else{
        int e;
        printf("Enter element to be inserted\n");
        scanf("%d",&e);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data=e;
        newnode->next=NULL;
        rear->next=newnode;
        rear=rear->next;
        *size = *size +1;
    }
}
void pop(int *size){
    if(*size==0){
        printf("queue is empty \n");
    }
    else{
        printf("%d has been popped\n",front->data);
        front=front->next;
        *size = *size -1;
    }
    

}
void display(int *size){
     if(*size==0){
        printf("queue is empty \n");

    }
    else if(*size ==1){
        printf("%d ",rear->data);
    }
    else{
        struct node *temp;
        temp=front;
        while(temp->next!=rear){
            printf("%d ",temp->data);
            temp=temp->next;
        }

        printf("%d ",temp->data);
        printf("%d",temp->next->data);
    }
}
int main()
{
    int n,op=1,size=0;
    printf("Enter size of queue : ");
    scanf("%d",&n);
    while(op!=4){
        printf("\nEnter 1 : PUSH || 2 : POP || 3 : Display || 4 : Exit \n ");
        scanf("%d",&op);
        switch (op){
            case 1:
                push(&size,n);
                break;
            case 2:
                pop(&size);
                break;
            case 3:
                display(&size);
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