// Centrality Measures ADT interface
// COMP2521 Assignment 2
// Written by Zheng Luo (z5206267@ad.unsw.edu.au) on April/2021

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "CentralityMeasures.h"
#include "FloydWarshall.h"
#include "Graph.h"

static EdgeValues initiateEdgeValueStruct(Graph g);
static double numberOfEdgePasses(int edgeSrc, int edgeDes, 
								 ShortestPaths sps, EdgeValues evs);
/**
 * Finds  the  edge  betweenness  centrality  for each edge in the given
 * graph and returns the results in a  EdgeValues  structure.  The  edge
 * betweenness centrality of a non-existant edge should be set to -1.0.
 */
EdgeValues edgeBetweennessCentrality(Graph g) {
	// Implement the framework for EdgeValues.
	EdgeValues evs = initiateEdgeValueStruct(g);
	// Find the shortest pair for all nodes.
	ShortestPaths sps = FloydWarshall(g);

	// Calculate the number of shortest paths through current edge
	// Which means the number of appearance of current edge in sps.next
	// Determine the edge betweenness in evs.values,
	// by looping thro the 2d array.
	for (Vertex i = 0; i < evs.numNodes; i++) {
		for (Vertex j = 0; j < evs.numNodes; j++) {
			// Determine the path 
			// if there are adjacent and a path exist.
			if (GraphIsAdjacent(g, i, j) == true && sps.next[i][j] != -1) {
				evs.values[i][j] = numberOfEdgePasses(i, j, sps, evs);
			}
		}
	}

	// Free all memories related to FloydWarshall.
	freeShortestPaths(sps);

	return evs;
}

// This function implement the framework for EdgeValues,
// allocate and assign memories for evs.numNodes and evs.values,
// and return EdgeValues evs at the end.
static EdgeValues initiateEdgeValueStruct(Graph g) {
	// Allocate spaces for edgevalues evs.
	EdgeValues evs;
	evs.numNodes = GraphNumVertices(g);
	evs.values = malloc(evs.numNodes * sizeof(double *));
	for (int i = 0; i < evs.numNodes; i++) {
		evs.values[i] = malloc(evs.numNodes * sizeof(double));
	}
	for (int i = 0; i < evs.numNodes; i++) {
		for (int j = 0; j < evs.numNodes; j++) {
			evs.values[i][j] = -1.0;
		}
	}
	return evs;
}

// This function searchs for number of edge passed thro the current edge,
// and returns the number of passes as double.
static double numberOfEdgePasses(int edgeSrc, int edgeDes, 
								 ShortestPaths sps, EdgeValues evs) {
	double counterEdgePasses = 0.0;
	for (int i = 0; i < evs.numNodes; i++) {
		for (int j = 0; j < evs.numNodes; j++) {
			int a = i;
			int b = j;
			// Keep searching until there is no path.
			while (sps.next[a][b] != -1) {
				int k = sps.next[a][b];
				if ((a == edgeSrc && k == edgeDes)) {
					counterEdgePasses++;
				}
				a = k;
			}
		}
	}
	return counterEdgePasses;
}

/**
 * Prints  the  values in the given EdgeValues structure to stdout. This
 * function is purely for debugging purposes and will NOT be marked.
 */
void showEdgeValues(EdgeValues evs) {

}

/**
 * Frees all memory associated with the given EdgeValues  structure.  We
 * will call this function during testing, so you must implement it.
 */
void freeEdgeValues(EdgeValues evs) {
	for (Vertex i = 0; i < evs.numNodes; i++) {
		free(evs.values[i]);
	}
	free(evs.values);

}


