// Implementation of the undirected weighted graph ADT

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int nV;      // #vertices
	int nE;      // #edges
	int **edges; // matrix of weights (0 == no edge)
} GraphRep;

static int validVertex(Graph g, Vertex v);

////////////////////////////////////////////////////////////////////////

Graph GraphNew(int nV)
{
	assert(nV > 0);

	Graph new = malloc(sizeof(*new));
	assert(new != NULL);
	new->nV = nV;
	new->nE = 0;

	new->edges = calloc(nV, sizeof(int *));
	assert(new->edges != NULL);
	for (int v = 0; v < nV; v++) {
		new->edges[v] = calloc(nV, sizeof(int));
		assert(new->edges[v] != 0);
	}

	return new;
}

void GraphFree(Graph g)
{
	assert(g != NULL);
	for (int v = 0; v < g->nV; v++)
		free(g->edges[v]);
	free(g->edges);
	free(g);
}

////////////////////////////////////////////////////////////////////////

void GraphInsertEdge(Graph g, Vertex v, Vertex w, int weight)
{
	assert(g != NULL && validVertex(g, v) && validVertex(g, w));

	if (g->edges[v][w] != 0 && g->edges[w][v] != 0)
		return; // an edge already exists; do nothing.

	g->edges[v][w] = weight;
	g->edges[w][v] = weight;
	g->nE++;
}

void GraphRemoveEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validVertex(g, v) && validVertex(g, w));
	if (g->edges[v][w] == 0 && g->edges[w][v] == 0)
		return; // the edge doesn't exist; do nothing.

	g->edges[v][w] = 0;
	g->edges[w][v] = 0;
	g->nE--;
}

////////////////////////////////////////////////////////////////////////

/**
 * Finds  the  shortest path (in terms of the number of hops) from `src`
 * to `dest` such that no edge on the path has weight larger than `max`.
 * Stores  the  path  in the given `path` array including both `src` and
 * `dest` and returns the number of vertices stored in the  path  array.
 * Returns 0 if there is no such path.
 */
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path)
{
	int visited[30] = {[0 ... 29] = -1};
	visited[src] = src;
	bool found = false;
	assert(g != NULL);
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	// Store src into path array
	// path[0] = src;
	// Initiate an array to store neighbours
	int *tmpNeighbour = malloc(1000 * sizeof(int));

	while (found == false && QueueIsEmpty(q) == false) {
		Vertex v = QueueDequeue(q);
		if (v == dest) {
			found = true;
		}
		else {
			int counterForNeighbour = 0;
			// Searching for next available neighbours,
			// put it into tmpNeighbour if found.
			for (int i = 0; i < g->nV; i++) {
				if (g->edges[v][i] != 0) {
					tmpNeighbour[counterForNeighbour] = g->edges[v][i];
					counterForNeighbour++;
				}
			}
			int SizeOfNeighbour = counterForNeighbour;
			int counterForMin;
			bool enqueueFinished = false;
			// Then we enqueue the neighbour in ascending order.
			while (enqueueFinished != true) {
				Vertex min = max;
				for (int counterForEnqueue = 0; 
				counterForEnqueue < SizeOfNeighbour; 
				counterForEnqueue++) {
					if (min > tmpNeighbour[counterForEnqueue]) {
						min = tmpNeighbour[counterForEnqueue];
						counterForMin = counterForEnqueue;
					}
				}
				if (min != max && visited[counterForMin] == -1) {
					QueueEnqueue(q, counterForMin);
					visited[counterForMin] = v;
					tmpNeighbour[counterForMin] = max;
				}
				else {
					enqueueFinished = true;
				}
			}
		}
	}
	int *tmpArray = malloc(30 * sizeof(int));
	if (found == true) {
		int tmp = dest;
		int counterForVisited = 0;
		// Put the path back into a tmp array in reverse way
		while (tmp != src) {
			tmpArray[counterForVisited] = visited[tmp];
			printf("last connected to: %d\n", tmpArray[counterForVisited]);
			counterForVisited++;
			tmp = visited[tmp];
		}
		// Adding src
		tmpArray[counterForVisited] = visited[tmp];
		// convert into normal way and put it into path
		int sizeOfPath = sizeof *tmpArray / sizeof(int);
		int counter = 0;
		for (int i = sizeOfPath; i >= 0; i--) {
			path[counter] = tmpArray[i];
			printf("%d\n", path[counter]);
			counter++;
		}
		return sizeOfPath + 1;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////

void GraphShow(Graph g, char **names)
{
	assert(g != NULL);
	printf("#vertices=%d, #edges=%d\n\n", g->nV, g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf("%d %s\n", v, names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf("\t%s (%d)\n", names[w], g->edges[v][w]);
			}
		}
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static int validVertex(Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

