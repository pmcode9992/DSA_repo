#include<stdio.h>
#include<stdbool.h> 
#include<string.h>

#define INF 9999999

#define V 7

int G[V][V] = {
  {0, 1, 4, 0, 0,0,0},
  {1, 0, 0, 3, 6,0,0},
  {4, 0, 0,2, 0,5,0},
  {0, 3, 2, 0, 2,4,0},
  {0, 0, 0, 2, 2,7},
  {0,0,5,4,2,0,6},
  {0,0,0,0,7,6,0}};

int main() {
  int num_of_edges; 
  int selected[V];
  char NODES[7]={'A','B','C','D','E','F','G'};
  memset(selected, false, sizeof(selected));
  num_of_edges = 0;
  selected[0] = true;

  int x;
  int y; 



  printf("Edge : Weight\n");

  while (num_of_edges < V - 1) {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%c - %c : %d\n", NODES[x], NODES[y], G[x][y]);
    selected[y] = true;
    num_of_edges++;
  }

  return 0;
}