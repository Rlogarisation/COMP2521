/*
Your task is to write a function, furthestReachable, 
that returns the furthest vertex that is reachable from a given source vertex. 
If there are multiple furthest vertices, 
return the one with the largest vertex number. 
If the source vertex is not connected to any other vertices, 
return the source vertex.

Examples
Your program should behave like these examples:


$ ./testFurthestReachable 
Enter number of vertices: 14
Enter number of edges: 12
Enter edges in the form v-w: 0-3 0-8 0-10 1-5 1-9 2-10 3-8 3-12 4-6 4-7 4-11 7-13

Graph: nV = 14
Edges:
 0: 0-3 0-8 0-10
 1: 1-5 1-9
 2: 2-10
 3: 3-0 3-8 3-12
 4: 4-6 4-7 4-11
 5: 5-1
 6: 6-4
 7: 7-4 7-13
 8: 8-0 8-3
 9: 9-1
10: 10-0 10-2
11: 11-4
12: 12-3
13: 13-7

Enter the source vertex: 10
Furthest vertex reachable from vertex 10: 12
Enter the source vertex: 12
Furthest vertex reachable from vertex 12: 2
Enter the source vertex: 5
Furthest vertex reachable from vertex 5: 9
Enter the source vertex: 6
Furthest vertex reachable from vertex 6: 13
Enter the source vertex: (Ctrl + D)
		

$ ./testFurthestReachable 
Enter number of vertices: 12
Enter number of edges: 7
Enter edges in the form v-w: 0-1 2-3 3-4 5-10 5-9 9-11 10-11

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

Enter the source vertex: 0
Furthest vertex reachable from vertex 0: 1
Enter the source vertex: 3
Furthest vertex reachable from vertex 3: 4
Enter the source vertex: 5
Furthest vertex reachable from vertex 5: 11
Enter the source vertex: 6
Furthest vertex reachable from vertex 6: 6
Enter the source vertex: 

Hint1:
One way to start would be 
to find the distances of each vertex from the starting vertex.

Hint2:
To get the distances of each vertex from the starting vertex, 
you'll need to use breadth-first search, 
which gives you a predecessor array from which you can calculate the distances.

*/

// ALL STANDARD ANSWER BELOW:
// Comment: No difficult, but many small parts.

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

static int *getDistances(Graph g, int src);
static int *bfs(Graph g, int v);

int furthestReachable(Graph g, int src) {
	int *dist = getDistances(g, src);
	
	int furthest = src;
	for (int v = 0; v < GraphNumVertices(g); v++) {
		if (dist[v] != -1 && dist[v] >= dist[furthest]) {
			furthest = v;
		}
	}
	
	return furthest;
}

// gets the distances of all vertices from src
static int *getDistances(Graph g, int src) {
	int *pred = bfs(g, src);

	int nV = GraphNumVertices(g);
	int *distances = malloc(nV * sizeof(int));
	for (int v = 0; v < nV; v++) {
		if (pred[v] == -1) {
			distances[v] = -1;
		} else {
			int distance = 0;
			int curr = v;
			while (curr != src) {
				distance++;
				curr = pred[curr];
			}
			distances[v] = distance;
		}
	}
	
	free(pred);
	return distances;
}

// performs a bfs starting at src and returns an array of predecessors
static int *bfs(Graph g, int src) {
	int nV = GraphNumVertices(g);
	int *pred = malloc(nV * sizeof(int));
	for (int i = 0; i < nV; i++) {
		pred[i] = -1;
	}
	pred[src] = src;
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		int curr = QueueDequeue(q);
		for (int next = 0; next < nV; next++) {
			if (GraphIsAdjacent(g, curr, next) && pred[next] == -1) {
				pred[next] = curr;
				QueueEnqueue(q, next);
			}
		}
	}
	QueueFree(q);
	
	return pred;
}


