#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;

};
struct node *root;

void push(int *top,int n){
    if(*top==n-1){
        printf("STACK IS FULL!!\n");
    }
    else{
        int e;
        printf("Enter element to enter : ");
        scanf("%d",&e);
        *top=*top+1;
        if(root==NULL){
            struct node *newnode;
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data=e;
            newnode->next=NULL;
            newnode->prev=NULL;
            root=newnode;
        }
        else{
            struct node *newnode;
            newnode = (struct node *)malloc(sizeof(struct node));
            struct node *temp;
            temp=root;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            newnode->data=e;
            newnode->next=NULL;
            newnode->prev=temp;
            temp->next=newnode;
            
        }
        printf("\n%d added to stack successfully!!\n",e);
    }
}
void pop(int *top){
    if(*top==-1){
        printf("STACK IS EMPTY!!\n");
    }
    else{
        *top=*top-1;
        struct node *temp;
            temp=root;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            temp->next=NULL;
        printf("Element deleted successfully!!\n");
    }
}
void display(int *top){
    if(*top==-1){
        printf("STACK IS EMPTY!!\n");
    }
    else{
        printf("Stack elements are : ");
        struct node *temp;
        temp=root;
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
            }
        printf("%d ",temp->data);
        printf("\n");
    }
}

void reverse_display(int *top){
    if(*top==-1){
        printf("STACK IS EMPTY!!\n");
    }
    else{
        printf("Stack elements are : ");
        struct node *temp;
        temp=root;
        while(temp->next!=NULL){
            temp = temp->next;
            }
        while(temp->prev!=NULL){
            printf("%d ",temp->data);
            temp=temp->prev;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}
int main()
{
    int n,op=1,top=-1;

    printf("Menu driven program for STACK Doubly Linked List implementation\n");
    printf("Enter size of stack\n");
    scanf("%d",&n);
    while(op!=5){
        printf("Enter 1 : PUSH || 2 : POP || 3 : Display || 4 : Display in reverse order || 5 : Exit \n ");
        scanf("%d",&op);
        switch (op){
            case 1:
                push(&top,n);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(&top);
                break;
            case 4:
                reverse_display(&top);
                break;
            case 5:
                printf("Exit Successful!!\n");
                break;
            default:
                printf("Incorrect input entered\n");
                break;
        }
    }
    return 0;
}