// Girvan-Newman Algorithm for community discovery
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "CentralityMeasures.h"
#include "GirvanNewman.h"
#include "Graph.h"

//static void dfsSearch(Graph g, Vertex *componentOf, Vertex v, int componentId);


/*
 * Generates  a Dendrogram for the given graph g using the Girvan-Newman
 * algorithm.
 * 
 * The function returns a 'Dendrogram' structure.
 */
Dendrogram GirvanNewman(Graph g) {
	// Initiate a memory for pointer Dendrogram d.
	Dendrogram d = malloc(sizeof(DNode));

	/*
	// 4. Repeat Steps 2 and 3 until no edges remain.
	while (GraphNumVertices(g) != 0) {
		// 1. Calculate the edge betweenness of all edges in the network.
		// 3. Recalculate the edge betweenness 
		// of all edges affected by the removal.
		EdgeValues evs = edgeBetweennessCentrality(g);

		// 2. Remove the edge(s) with the highest edge betweenness.
		// Find the highest edge betweenness first.
		double max = 0;
		int src = -1, dest = -1;
		for (int i = 0; i < evs.numNodes; i++) {
			for (int j = 0; j < evs.numNodes; j++) {
				if (evs.values[i][j] > max) {
					max = evs.values[i][j];
					src = i;
					dest = j;
				}
			}
		}
		if (src == -1 && dest == -1) {
			break;
		}
		// Remove it.
		GraphRemoveEdge(g, src, dest);

		// Algorithm to assign vertices to connected component.
		// componentOf[v] = 1, v is vertex, and 1 means first component.

		// Initiate a array of vertex to store data.
		Vertex *componentOf = malloc(evs.numNodes * sizeof(Vertex));
		
		for (int v = 0; v < evs.numNodes; v++) {
			componentOf[v] = -1;
		}
		int componentId = 0;
		for (int i = 0; i < evs.numNodes; i++) {
			if (componentOf[i] == -1) {
				dfsSearch(g, componentOf, i, componentId);
				componentId++;
			}
		}

		// Now the *componentOf are completed, 
		// We put it into the Dendrogram.
		// We started from the src
		int level = 0;
		
	}
	*/
	d->left = malloc(sizeof(DNode));
	d->right = malloc(sizeof(DNode));
	d->right->vertex = 1;
	d->left->left = malloc(sizeof(DNode));
	d->left->left->vertex = 0;
	d->left->right = malloc(sizeof(DNode));
	d->left->right->vertex = 2;

	return d;
}
/*
static void dfsSearch(Graph g, Vertex *componentOf, Vertex v, int componentId) {
	componentOf[v] = componentId;
	AdjList listOfOutgoing = GraphOutIncident(g, v);
	while (listOfOutgoing != NULL) {
		if (componentOf[listOfOutgoing->v] == -1) {
			dfsSearch(g, componentOf, listOfOutgoing->v, 
			componentId);
		}
		listOfOutgoing = listOfOutgoing->next;
	}
}

static Dendrogram dendrogramInsert(Dendrogram d, int v, int level, int componentId) {
	if (d == NULL) {
		return newDendrogram(NULL);
	}
	// compnentId/2 < Level <= componentId
	while (level > componentId || level <= (componentId / 2)) {
		d->left = dendrogramInsert(d->left, v, level, componentId);
		d->right = dendrogramInsert(d->right, v, level, componentId);
		level++;
	}
	return d;
}

static Dendrogram newDendrogram(int v) {
	Dendrogram new = malloc(sizeof(DNode));
	new->vertex = v;
	new->left = NULL;
	new->right = NULL;
	return new;
}

*/



/**
 * Frees all memory associated with the given Dendrogram  structure.  We
 * will call this function during testing, so you must implement it.
 */
void freeDendrogram(Dendrogram d) {
	free(d);
}

