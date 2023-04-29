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
    int adjmatrix[7][7];
    char NODES[7]={'A','B','C','D','E','F','G'};
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
        int min= 100;
        for(int i=0;i<6;i++){
            for(int j=i+1;j<7;j++){
                if(adjmatrix[i][j]!=0 && adjmatrix[i][j]<min){
                    min=adjmatrix[i][j];
                    a=i;
                    b=j;
                }
            }
            
        }
        printf("%c is connected to %c\n",NODES[a],NODES[b]);
        connections++;
        adjmatrix[a][b]=0;
        for(int i=0;i<7;i++){
            adjmatrix[a][i]=0;
        }


        if(connections==6){
            done=1;
        }

    }
}
