/*

Your task is to write a function, numReachable, 
that returns the number of vertices that 
are reachable from a source vertex in the given graph, 
including the source vertex itself.

Examples
Your program should behave like these examples:


$ ./testNumReachable 
Enter number of vertices: 12
Enter number of edges: 11
Enter edges in the form v-w: 0-8 0-3 3-8 0-10 10-2 1-9 1-5 5-9 4-6 4-7 4-11

Graph: nV = 12
Edges:
 0: 0-3 0-8 0-10
 1: 1-5 1-9
 2: 2-10
 3: 3-0 3-8
 4: 4-6 4-7 4-11
 5: 5-1 5-9
 6: 6-4
 7: 7-4
 8: 8-0 8-3
 9: 9-1 9-5
10: 10-0 10-2
11: 11-4

Enter the source vertex: 2
Number of vertices reachable from vertex 2: 5
Enter the source vertex: 1
Number of vertices reachable from vertex 1: 3
Enter the source vertex: 4
Number of vertices reachable from vertex 4: 4
Enter the source vertex: (Ctrl + D)
		

$ ./testNumReachable 
Enter number of vertices: 12
Enter number of edges: 7
Enter edges in the form v-w: 0-1 2-3 3-4 5-9 5-10 9-11 10-11

Graph: nV = 12
Edges:
 0: 0-1
 1: 1-0
 2: 2-3
 3: 3-2 3-4
 4: 4-3
 5: 5-9 5-10
 6:
 7:
 8:
 9: 9-5 9-11
10: 10-5 10-11
11: 11-9 11-10

Enter the source vertex: 3
Number of vertices reachable from vertex 3: 3
Enter the source vertex: 6
Number of vertices reachable from vertex 6: 1
Enter the source vertex: 5
Number of vertices reachable from vertex 5: 4
Enter the source vertex: (Ctrl + D)
*/



#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"


// Standard answer: wowow!
static int doNumReachable(Graph g, int v, int *visited);

int numReachable(Graph g, int src) {
	int *visited = calloc(GraphNumVertices(g), sizeof(int));
	int result = doNumReachable(g, src, visited);
	free(visited);
	return result;
}

static int doNumReachable(Graph g, int v, int *visited) {
	visited[v] = 1;
	int result = 1;
	for (int w = 0; w < GraphNumVertices(g); w++) {
		if (GraphIsAdjacent(g, v, w) && !visited[w]) {
			result += doNumReachable(g, w, visited);
		}
	}
	return result;
}

