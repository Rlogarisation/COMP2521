// Girvan-Newman Algorithm for community discovery
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "CentralityMeasures.h"
#include "GirvanNewman.h"
#include "Graph.h"

#define HEAD -1

static Dendrogram newDendrogram(int v);
static int calculateComponentSeparation(Graph g, Vertex *componentOf, 
										int numOfNodes);
static void bfsSearch(Graph g, Vertex *componentOf, Vertex v, int componentId);
static Dendrogram treeSearchAndInsert(Dendrogram d, Vertex searchValue, 
									  Vertex src, Vertex dest);
static void storingParentVertex(Vertex *componentOf, Vertex *parentOf, 
								int numOfNodes, Vertex src, Vertex dest);

/*
 * Generates a Dendrogram for the given graph g using the Girvan-Newman
 * algorithm.
 * 
 * The function returns a 'Dendrogram' structure.
 */
Dendrogram GirvanNewman(Graph g) {
	// 1. Calculate the edge betweenness of all edges in the network.
	EdgeValues evs = edgeBetweennessCentrality(g);

	// Initiate certain memory for pointer Dendrogram d.
	Dendrogram d = newDendrogram(HEAD);
	// Initiate an array of vertex to store component catogory.
	Vertex *componentOf = malloc(evs.numNodes * sizeof(Vertex));
	// Initiate an array to store the imformation (vertex) of its parent.
	Vertex *parentOf = malloc(evs.numNodes * sizeof(Vertex));
	for (int i = 0; i < evs.numNodes; i++) {
		parentOf[i] = -1;
	}
	int componentIdPrev = 1, componentId = 0;
	Vertex src = -1, dest = -1;
	

	// 4. Repeat Steps 2 and 3 until no edges remain.
	while (GraphNumVertices(g) != 0) {
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
		// Exit the while loop if no edge betweenness > 0
		if (max == -1) {
			break;
		}

		// Remove selected edges.
		GraphRemoveEdge(g, src, dest);
		

		// Algorithm to assign vertices to connected component.
		// e.g. componentOf[v] = 1, v is vertex, and 1 means first component.
		if (componentId != 0) {
			componentIdPrev = componentId;
		}
		componentId = calculateComponentSeparation(g, componentOf, 
												   evs.numNodes);
		// If number of components did not increased after edge removal,
		// then remove the edge with same betweenness until different.
		while (componentId == componentIdPrev) {
			for (int i = 0; i < evs.numNodes; i++) {
				for (int j = 0; j < evs.numNodes; j++) {
					if (evs.values[i][j] >= max && i != src && j != dest) {
						GraphRemoveEdge(g, i, j);
						src = i;
						dest = j;
					}
				}
			}
			componentId = calculateComponentSeparation(g, componentOf, 
													   evs.numNodes);
		}
		
		// Insert src and dest into required location.
		if (parentOf[src] == HEAD) {
			d->left = newDendrogram(src);
			d->right = newDendrogram(dest);
		}
		else {
			d = treeSearchAndInsert(d, parentOf[src], src, dest);
		}
		// Exit the loop if the number of components are enough.
		if (componentId == evs.numNodes) {
			break;
		}

		// Update the parents of vertices.
		storingParentVertex(componentOf, parentOf, evs.numNodes, src, dest);
	}

	free(componentOf);
	free(parentOf);

	return d;
}

// Allocate memories for DNode in dendrogram, 
// newDendrogram takes one input v, 
// used to assign the vertex value in dendrogram,
// this function returns the new dendrogram.
static Dendrogram newDendrogram(int v) {
	Dendrogram new = malloc(sizeof(DNode));
	new->vertex = v;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// This function searchs number of components and their contents in a graph,
// and update into the array componentOf.
// This function returns the number of components in the graph as int type.
// The componentOf[] can be illustrated thro an example below:
// 0->1->2->3->4->5->6->7
// the link break between 3 and 4,
// 0	1	2	3	4	5	6	7
// 0	0	0	0	1	1	1	1
// This array componentOf indicates the component of its index belongs to.
static int calculateComponentSeparation(Graph g, Vertex *componentOf, 
										int numOfNodes) {
	for (int v = 0; v < numOfNodes; v++) {
		componentOf[v] = -1;
	}
	int componentId = 0;
	for (int i = 0; i < numOfNodes; i++) {
		if (componentOf[i] == -1) {
			bfsSearch(g, componentOf, i, componentId);
			componentId++;
		}
	}
	return componentId;
}

// The bfsSearch function is a 
// void type sub-function for calculateComponentSeparation.
// This function search for links/edges between vertices,
// and categorised them into different components,
// a component is consider to be no incoming or outcoming edges 
// with other vertices not in the component.
static void bfsSearch(Graph g, Vertex *componentOf, 
					  Vertex v, int componentId) {
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

static Dendrogram treeSearchAndInsert(Dendrogram d, Vertex searchValue, 
									  Vertex src, Vertex dest) {
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

static void storingParentVertex(Vertex *componentOf, Vertex *parentOf, 
int numOfNodes, Vertex src, Vertex dest) {
	int srcComponent = componentOf[src];
	int destComponent = componentOf[dest];
	for (int i = 0; i < numOfNodes; i++) {
		if (componentOf[i] == srcComponent) {
			parentOf[i] = src;
		}
		else if (componentOf[i] == destComponent) {
			parentOf[i] = dest;
		}
		// End the whole programme if compoentOf[i] == parentOf[i] for all
	}
}














/**
 * Frees all memory associated with the given Dendrogram  structure.  We
 * will call this function during testing, so you must implement it.
 */
void freeDendrogram(Dendrogram d) {
	free(d);
}

