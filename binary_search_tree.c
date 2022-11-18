//DELETION CODE WRONG

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void del(struct node *temp,int e);

int inordersuccessor(struct node *temp){
    if(temp->left==NULL && temp->right==NULL){
        int t = temp->data;
        temp=NULL;
        return t;
    }
    else{
        if(temp->left!=NULL){
            inordersuccessor(temp->left);
        }
        else{
            int t = temp->data;
            del(temp,temp->data);
            return t;
        }
    }
    return -1;
}

void join(struct node *temp,struct node *newnode){
    if(newnode->data < temp->data){
        if(temp->left!=NULL){
            join(temp->left,newnode);
        }
        else{
            temp->left=newnode;
        }
    }
    else{
        if(temp->right!=NULL){
            join(temp->right,newnode);
        }
        else{
            temp->right=newnode;
        }
        
    }
    printf("%d added successfully\n",newnode->data);

};

void del(struct node *temp,int e){
    if(temp->data==e){
        if(temp->left==NULL && temp->right==NULL){
            temp=NULL;
        }
        else if(temp->left!=NULL && temp->right!=NULL){
            int t = inordersuccessor(temp->right);
            temp->data=t;
        }
        else{
            if(temp->right==NULL){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
    }
    else if(temp==NULL){
        printf("Element not present in tree\n");
    }
    else {
        if(e<temp->data){
            del(temp->left,e);
        }
        else{
            del(temp->right,e);
        }
    }
}
void insert(){
    int e;
    printf("Enter element to insert \n");
    scanf("%d",&e);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL){
        root = newnode;
    }
    else{
        struct node *temp;
        temp = root;
        join(temp,newnode);
    }

}
void delete(){
    printf("Enter element to delete\n");
    int e;
    scanf("%d",&e);
    if(root==NULL){
        printf("Tree is empty\n");
    }
    else{
        struct node *temp;
        temp = root;
        del(temp,e);
        printf("%d deleted \n",e);
    }
    
}
void s(struct node *temp, int e){
    if(temp==NULL){
        printf("Not found\n");
    }
    if(e==temp->data){
        printf("%d Found\n",e);
    }
    else if(e<temp->data){
        printf("%d ->",temp->data);
        s(temp->left,e);
    }
    else{
        printf("%d ->",temp->data);
        s(temp->right,e);
    }

}
void search(){
    printf("Enter element to search \n");
    int e;
    scanf("%d",&e);
    if(root==NULL){
        printf("Tree is empty\n");
    }
    if(root->data==e){
        printf("%d present at root\n",e);
    }
    else{
        struct node *temp;
        temp = root;
        s(temp,e);
    }
}
int inorder(struct node *temp){
        if(temp==NULL){
            return 0;
        }
        else{
            inorder(temp->left);
            printf("%d -> ",temp->data);
            inorder(temp->right);
        }
        printf("\n");
        return 0;
    
}
int preorder(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    printf("%d -> ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
    printf("\n");
    return 0;
}
int postorder(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d -> ",temp->data);
    printf("\n");
    return 0;
}

int main()
{
    int op=1;
    while(op!=0){
        printf("Enter 0: quit 1: insert node 2: delete node 3: search 4: inorder 5: preorder 6: postorder \n");
        scanf("%d",&op);
        switch(op){
            case 0: 
                printf("Exit successful\n");
                break;
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            default:
                printf("Incorrect input\n");
                break;
        }
    }
}
