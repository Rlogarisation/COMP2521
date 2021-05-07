
/*
Your task is to write a function, shortestDistance, 
that returns the number of edges on the shortest path between 
two vertices in the given graph. 
If there is no path between the two vertices, return -1.

Examples
Your program should behave like these examples:


$ ./testShortestDistance 
Enter number of vertices: 6
Enter number of edges: 5
Enter edges in the form v-w: 0-1 1-2 2-3 3-4 4-5

Graph: nV = 6
Edges:
 0: 0-1
 1: 1-0 1-2
 2: 2-1 2-3
 3: 3-2 3-4
 4: 4-3 4-5
 5: 5-4

Enter two vertices: 0 0
The shortest distance between vertices 0 and 0 is: 0
Enter two vertices: 0 3
The shortest distance between vertices 0 and 3 is: 3
Enter two vertices: 4 0
The shortest distance between vertices 4 and 0 is: 4
Enter two vertices: 1 5
The shortest distance between vertices 1 and 5 is: 4
Enter two vertices: (Ctrl + D)
		

$ ./testShortestDistance 
Enter number of vertices: 10
Enter number of edges: 10
Enter edges in the form v-w: 0-1 0-2 1-3 1-6 2-9 3-4 3-5 5-7 5-9 7-8

Graph: nV = 10
Edges:
 0: 0-1 0-2
 1: 1-0 1-3 1-6
 2: 2-0 2-9
 3: 3-1 3-4 3-5
 4: 4-3
 5: 5-3 5-7 5-9
 6: 6-1
 7: 7-5 7-8
 8: 8-7
 9: 9-2 9-5

Enter two vertices: 0 7 
The shortest distance between vertices 0 and 7 is: 4
Enter two vertices: 8 2
The shortest distance between vertices 8 and 2 is: 4
Enter two vertices: 5 6
The shortest distance between vertices 5 and 6 is: 3
Enter two vertices: (Ctrl + D)
		

$ ./testShortestDistance 
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

Enter two vertices: 6 4
The shortest distance between vertices 6 and 4 is: 4
Enter two vertices: 0 5
The shortest distance between vertices 0 and 5 is: 3
Enter two vertices: 0 8
There is no path between vertices 0 and 8
Enter two vertices: (Ctrl + D)
*/

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int shortestDistance(Graph g, int src, int dest) {
	Queue q = QueueNew();

	int *visited = malloc(GraphNumVertices(g) * sizeof(int));
	// Set all to be -1
	for (int i = 0; i < GraphNumVertices(g); i++) {
		visited[i] = -1;
	}
	bool isFound = false;

	QueueEnqueue(q, src);
	visited[src] = src;

	while (!QueueIsEmpty(q) && isFound == false) {
		Vertex v = QueueDequeue(q);
		for (int w = 0; w < GraphNumVertices(g); w++) {
			if (GraphIsAdjacent(g, v, w) == true && visited[w] == -1) {
				visited[w] = v;
				if (v == dest) {
					isFound = true;
				}
				QueueEnqueue(q, w);
			}
		}
			
	}
	QueueFree(q);
	if (visited[dest] == -1) {
		free(visited);
		return -1;
	}

	// Count number of edges during the shortest path.
	Vertex prev = dest;
	int numEdges = 0;
	while (prev != src) {
		prev = visited[prev];
		numEdges++;
	}
	free(visited);
	return numEdges;
}


// Standard answer: similar:
// int shortestDistance(Graph g, int src, int dest) {
// 	// Standard BFS
// 	int nV = GraphNumVertices(g);
// 	int pred[nV];
// 	for (int i = 0; i < nV; i++) {
// 		pred[i] = -1;
// 	}
// 	pred[src] = src;
	
// 	bool found = false;
// 	Queue q = QueueNew();
// 	QueueEnqueue(q, src);
// 	while (!found && !QueueIsEmpty(q)) {
// 		Vertex curr = QueueDequeue(q);
// 		for (Vertex next = 0; next < nV; next++) {
// 			if (GraphIsAdjacent(g, curr, next) && pred[next] == -1) {
// 				pred[next] = curr;
// 				if (next == dest) {
// 					found = true;
// 				}
// 				QueueEnqueue(q, next);
// 			}
// 		}
// 	}
// 	QueueFree(q);
	
// 	// Calculate the distance using the predecessor array
// 	if (pred[dest] == -1) {
// 		return -1;
// 	}

// 	int distance = 0;
// 	Vertex curr = dest;
// 	while (curr != src) {
// 		distance++;
// 		curr = pred[curr];
// 	}
// 	return distance;
// }