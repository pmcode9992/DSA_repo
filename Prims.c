#include<stdio.h>
void display(int a[7][7]){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    
    int front=-1, rear=-1,c=0,d=0;
    int adjmatrix[7][7];
    char queue[7];
    char NODES[7]={'A','B','C','D','E','F','G'};
    queue[0]=NODES[0];
    printf("Enter adjacency matrix\n");
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(j<=i){
                adjmatrix[i][j]=0;
                continue;
            }
            printf("M[%c][%c]: ",NODES[i],NODES[j]);
            scanf("%d",&adjmatrix[i][j]);
        }
    }
    display(adjmatrix);
    int done=0,a=0,b=0,connections=0;
    while(done!=1){
        front=0;
        rear=0;
        int i=b;
        for(int j=i+1;j<7;j++){
            int min=100;
            if(adjmatrix[i][j]<min && adjmatrix[i][j]!=0){
                min=adjmatrix[i][j];
                a=i;
                b=j;
            }
        }
        printf("%c is connected to %c",NODES[a],NODES[b]);
        connections++;
        queue[c]=NODES[b];
        c++;
        rear++;
    }

}