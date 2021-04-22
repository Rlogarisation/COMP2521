// Girvan-Newman Algorithm for community discovery
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "CentralityMeasures.h"
#include "GirvanNewman.h"
#include "Graph.h"
static void bfsSearch(Graph g, Vertex *componentOf, Vertex v, int componentId);
static Dendrogram treeSearchAndInsert(Dendrogram d, Vertex searchValue, Vertex src, Vertex dest);
static Dendrogram newDendrogram(int v);

/*
 * Generates  a Dendrogram for the given graph g using the Girvan-Newman
 * algorithm.
 * 
 * The function returns a 'Dendrogram' structure.
 */
Dendrogram GirvanNewman(Graph g) {
	// Initiate a memory for pointer Dendrogram d.
	Dendrogram d = newDendrogram(-1);

	EdgeValues evs = edgeBetweennessCentrality(g);
	// Initiate a array of vertex to store data.
	Vertex *componentOf = malloc(evs.numNodes * sizeof(Vertex));
	int src = -1, dest = -1;
	Vertex parent = -1;

	// Initiate an array to store the imformation (vertex) of its parent.
	Vertex *parentOf = malloc(evs.numNodes * sizeof(Vertex));
	for (int i = 0; i < evs.numNodes; i++) {
		parentOf[i] = -1;
	}
	
	// 4. Repeat Steps 2 and 3 until no edges remain.
	while (GraphNumVertices(g) != 0) {
		// 1. Calculate the edge betweenness of all edges in the network.
		// 3. Recalculate the edge betweenness 
		// of all edges affected by the removal.
		EdgeValues evs = edgeBetweennessCentrality(g);

		

		// 2. Remove the edge(s) with the highest edge betweenness.
		// Find the highest edge betweenness first.
		double max = -1;
		for (int i = 0; i < evs.numNodes; i++) {
			for (int j = 0; j < evs.numNodes; j++) {
				if (evs.values[i][j] > max) {
					max = evs.values[i][j];
					src = i;
					dest = j;
				}
			}
		}
		if (max == -1) {
			break;
		}

		// Remove it.
		GraphRemoveEdge(g, src, dest);
		
			

		// Algorithm to assign vertices to connected component.
		// componentOf[v] = 1, v is vertex, and 1 means first component.
		for (int v = 0; v < evs.numNodes; v++) {
			componentOf[v] = -1;
		}
		int componentId = 0;
		for (int i = 0; i < evs.numNodes; i++) {
			if (componentOf[i] == -1) {
				bfsSearch(g, componentOf, i, componentId);
				componentId++;
			}
		}
		// Only 1 component
		if (componentId != 1) {

	
			//TEST
			printf("src = %d, dest = %d\n", src, dest);
			printf("ComponentOf: ");
			for (int i = 0; i < evs.numNodes; i++) {
				printf("%d ", componentOf[i]);
			}
			printf("\nparentOf: ");
			for (int i = 0; i < evs.numNodes; i++) {
				printf("%d ", parentOf[i]);
			}
			printf("\n");

			// Check the src and dest belong to which previous group.
			// When not in the first loop
			assert(parentOf[src] == parentOf[dest]);
			parent = parentOf[src];
		
			// Start of d
			if (parent == -1) {
				d->left = newDendrogram(src);
				d->right = newDendrogram(dest);
			}
			else {
				d = treeSearchAndInsert(d, parent, src, dest);
			}

			if (componentId == evs.numNodes) {
				break;
			}


			int srcComponent = componentOf[src];
			int destComponent = componentOf[dest];
			for (int i = 0; i < evs.numNodes; i++) {
				if (componentOf[i] == srcComponent) {
					parentOf[i] = src;
				}
				else if (componentOf[i] == destComponent) {
					parentOf[i] = dest;
				}
				// End the whole programme if compoentOf[i] == parentOf[i] for all
			}
			//TEST
			printf("src = %d, dest = %d\n", src, dest);
			printf("ComponentOf: ");
			for (int i = 0; i < evs.numNodes; i++) {
				printf("%d ", componentOf[i]);
			}
			printf("\nparentOf: ");
			for (int i = 0; i < evs.numNodes; i++) {
				printf("%d ", parentOf[i]);
			}
			printf("\n-----------------------------------------\n");
		}
		
	}

	return d;
}

static void bfsSearch(Graph g, Vertex *componentOf, Vertex v, int componentId) {
	componentOf[v] = componentId;
	AdjList listOfOutgoing = GraphOutIncident(g, v);
	AdjList listOfIncoming = GraphInIncident(g, v);
	while (listOfOutgoing != NULL) {
		if (componentOf[listOfOutgoing->v] == -1) {
			bfsSearch(g, componentOf, listOfOutgoing->v, 
			componentId);
		}
		listOfOutgoing = listOfOutgoing->next;
	}
	while (listOfIncoming != NULL) {
		if (componentOf[listOfIncoming->v] == -1) {
			bfsSearch(g, componentOf, listOfIncoming->v, 
			componentId);
		}
		listOfIncoming = listOfIncoming->next;
	}
}

static Dendrogram treeSearchAndInsert(Dendrogram d, Vertex searchValue, Vertex src, Vertex dest) {
	if (d == NULL) {
		return d;
	}

	if (d->vertex == searchValue) {
		d->left = newDendrogram(src);
		d->right = newDendrogram(dest);
		return d;
	}
	d->left = treeSearchAndInsert(d->left, searchValue, src, dest);
	d->right = treeSearchAndInsert(d->right, searchValue, src, dest);
	return d;
}


static Dendrogram newDendrogram(int v) {
	Dendrogram new = malloc(sizeof(DNode));
	new->vertex = v;
	new->left = NULL;
	new->right = NULL;
	return new;
}





/**
 * Frees all memory associated with the given Dendrogram  structure.  We
 * will call this function during testing, so you must implement it.
 */
void freeDendrogram(Dendrogram d) {
	free(d);
}

