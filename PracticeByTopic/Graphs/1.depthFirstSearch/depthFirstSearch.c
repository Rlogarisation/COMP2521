/*
Your task is to write a function, depthFirstSearch, 
that performs a depth first search on a graph starting at the given vertex. 
It should print out the vertices as they are visited. 
If a vertex has multiple neighbours, 
visit the neighbour with the smallest vertex number first.

Hint: You are not provided with a stack ADT, so you must use recursion.


Examples
Your program should behave like these examples:


$ ./testDepthFirstSearch 
Enter number of vertices: 9
Enter number of edges: 9
Enter edges in the form v-w: 0-1 0-7 1-2 1-5 3-4 3-5 3-6 3-7 5-8

Graph: nV = 9
Edges:
 0: 0-1 0-7
 1: 1-0 1-2 1-5
 2: 2-1
 3: 3-4 3-5 3-6 3-7
 4: 4-3
 5: 5-1 5-3 5-8
 6: 6-3
 7: 7-0 7-3
 8: 8-5

Enter src: 0
Depth first search starting at vertex 0: 0 1 2 5 3 4 6 7 8 
		

$ ./testDepthFirstSearch 
Enter number of vertices: 8
Enter number of edges: 8
Enter edges in the form v-w: 0-1 1-2 2-3 3-4 4-5 5-6 6-7 7-0

Graph: nV = 8
Edges:
 0: 0-1 0-7
 1: 1-0 1-2
 2: 2-1 2-3
 3: 3-2 3-4
 4: 4-3 4-5
 5: 5-4 5-6
 6: 6-5 6-7
 7: 7-0 7-6

Enter src: 3
Depth first search starting at vertex 3: 3 2 1 0 7 6 5 4 
		

$ ./testDepthFirstSearch 
Enter number of vertices: 10
Enter number of edges: 9
Enter edges in the form v-w: 0-1 1-2 1-3 2-4 2-5 3-5 3-6 7-8 8-9

Graph: nV = 10
Edges:
 0: 0-1
 1: 1-0 1-2 1-3
 2: 2-1 2-4 2-5
 3: 3-1 3-5 3-6
 4: 4-2
 5: 5-2 5-3
 6: 6-3
 7: 7-8
 8: 8-7 8-9
 9: 9-8

Enter src: 6
Depth first search starting at vertex 6: 6 3 1 0 2 4 5 
*/
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
static void dfs(Graph g, Vertex v, int *visited);


void depthFirstSearch(Graph g, int src) {
	int *arrayVisited = calloc(GraphNumVertices(g), sizeof(int));
	dfs(g, src, arrayVisited);
	free(arrayVisited);
}

static void dfs(Graph g, Vertex v, int *visited) {
	printf("%d ", v);
	visited[v] = 1;
	for (int i = 0; i < GraphNumVertices(g); i++) {
		if (GraphIsAdjacent(g, v, i) == true &&
			visited[i] == 0) {

			dfs(g, i, visited);
		}
	}
}


