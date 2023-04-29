#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int d){
    struct Node* newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//inorder traversal
void inorder(struct Node* temp){
    if(temp==NULL){
        return;
    }
    else{
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}

//preorder traversal
void preorder(struct Node* temp,int v[],int *top){
    
}

//postorder traversal
void postorder(struct Node* temp){

}

//Insert a node

int main()
{
    struct Node* root = NULL;
    root = (struct Node*)malloc(sizeof(struct Node));
    root = createNode(10);
    root->left=createNode(11);
    root->left->left=createNode(7);
    root->right=createNode(9);
    root->right->left=createNode(15);
    root->right->right=createNode(8);
    root->left->left->left=createNode(12);

    printf("Inorder traversal of tree is \n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of tree is \n");
    int v[10],top=-1;
    for(int i=0;i<10;i++){
        printf("%d ",v[i]);
    }
    preorder(root,v,&top);
    printf("\n");



}