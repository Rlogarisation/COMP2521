/*
Your task is to write a function, numWithin, 
that determines the number of vertices that are 
within a given distance of the given source vertex.

Examples
Your program should behave like these examples:


$ ./testNumWithin 
Enter number of vertices: 11
Enter number of edges: 10
Enter edges in the form v-w: 0-1 1-2 2-3 3-4 0-5 5-6 6-7 0-8 8-9 0-10

Graph: nV = 11
Edges:
 0: 0-1 0-5 0-8 0-10
 1: 1-0 1-2
 2: 2-1 2-3
 3: 3-2 3-4
 4: 4-3
 5: 5-0 5-6
 6: 6-5 6-7
 7: 7-6
 8: 8-0 8-9
 9: 9-8
10: 10-0

Enter the source vertex and maximum distance: 0 5
numWithin(g, 0, 5) = 11
Enter the source vertex and maximum distance: 0 4
numWithin(g, 0, 4) = 11
Enter the source vertex and maximum distance: 0 3
numWithin(g, 0, 3) = 10
Enter the source vertex and maximum distance: 0 2
numWithin(g, 0, 2) = 8
Enter the source vertex and maximum distance: 0 1
numWithin(g, 0, 1) = 5
Enter the source vertex and maximum distance: 0 0
numWithin(g, 0, 0) = 1
Enter the source vertex and maximum distance: (Ctrl + D)
		

$ ./testNumWithin 
Enter number of vertices: 11
Enter number of edges: 12
Enter edges in the form v-w: 0-1 0-2 0-6 0-7 1-2 2-3 2-5 3-4 6-7 7-8 7-10 8-9

Graph: nV = 11
Edges:
 0: 0-1 0-2 0-6 0-7
 1: 1-0 1-2
 2: 2-0 2-1 2-3 2-5
 3: 3-2 3-4
 4: 4-3
 5: 5-2
 6: 6-0 6-7
 7: 7-0 7-6 7-8 7-10
 8: 8-7 8-9
 9: 9-8
10: 10-7

Enter the source vertex and maximum distance: 1 1
numWithin(g, 1, 1) = 3
Enter the source vertex and maximum distance: 1 2
numWithin(g, 1, 2) = 7
Enter the source vertex and maximum distance: 1 3
numWithin(g, 1, 3) = 10
Enter the source vertex and maximum distance: 1 4
numWithin(g, 1, 4) = 11
Enter the source vertex and maximum distance: 4 1
numWithin(g, 4, 1) = 2
Enter the source vertex and maximum distance: 4 4
numWithin(g, 4, 4) = 8
Enter the source vertex and maximum distance: (Ctrl + D)

*/
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

static int *getDistances(Graph g, int src);
static int *bfs(Graph g, int src);

int numWithin(Graph g, int src, int dist) {
	int *distances = getDistances(g, src);

	int count = 0;
	for (int v = 0; v < GraphNumVertices(g); v++) {
		if (distances[v] >= 0 && distances[v] <= dist) {
			count++;
		}
	}

	free(distances);
	return count;
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


