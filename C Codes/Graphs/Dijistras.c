#include <stdio.h>
#define INFINITY 9999
#define MAX 10

//for printing path
void print(int parent[],int source,int dest){
	if(source==parent[dest])
		return;
	
	print(parent,source,parent[dest]);
	printf("%d->",parent[dest]);
}

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], parent[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
	for (i = 0; i < n; i++){
    	for (j = 0; j < n; j++){
      		if (Graph[i][j] == 0)
        		cost[i][j] = INFINITY;
      		else
        		cost[i][j] = Graph[i][j];
    	}
	}
	
	//Distance of all nodes from start node
	for (i = 0; i < n; i++) {
    	distance[i] = cost[start][i];
    	parent[i] = start;//intialzing parent of all node to be start node
    	visited[i] = 0;//mark all nodes un visited
  	}
	distance[start] = 0;//distance from start->start
  	visited[start] = 1;//visited start
  	count = 1;
  	
//iterate for relaxation
//every time it loops gets a new mindistance and nextnode,start->nectnode->...from that next node gets the distance of
//further nodes and if its less than existing performs relaxation 
	for(count=1;count<n;count++) {
		mindistance = INFINITY;
		for (i = 0; i < n; i++){
    		if (!visited[i] && distance[i] < mindistance ) {
        		mindistance = distance[i];
        		nextnode = i;
      		}
		}
		
		//now the node which is closest to start is visited hence mark it as 1
    	visited[nextnode] = 1;
    	
    	//now check for next shortest distance from source->nextnode->....
		for (i = 0; i < n; i++){
      		if (!visited[i]){
      			//Relaxation
        		if (mindistance + cost[nextnode][i] < distance[i]) {
          			distance[i] = mindistance + cost[nextnode][i];
          			parent[i] = nextnode;//mark nextnode as parent of that node 
        		}
        	}
    	}
  }

  // Printing the distance and path
	for (i = 0; i < n; i++){
    	if (i != start) {
      		printf("\nDistance from source to %d: %d  Path: ", i, distance[i]);
      		printf("%d->",start);
			print(parent,start,i);
			printf("%d",i);
    	}
	}
}
int main() {
  int Graph[MAX][MAX],n,source;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;

  source = 0;
  printf("source : %d",source);
  Dijkstra(Graph, n, source);

  return 0;
}
