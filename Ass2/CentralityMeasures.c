// Centrality Measures ADT interface
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "CentralityMeasures.h"
#include "FloydWarshall.h"
#include "Graph.h"


double numberOfEdgePasses(int edgeSrc, int edgeDes, ShortestPaths sps, EdgeValues e);
/**
 * Finds  the  edge  betweenness  centrality  for each edge in the given
 * graph and returns the results in a  EdgeValues  structure.  The  edge
 * betweenness centrality of a non-existant edge should be set to -1.0.
 */
EdgeValues edgeBetweennessCentrality(Graph g) {
	// Allocate spaces for edgevalues e.
	EdgeValues e;
	e.numNodes = GraphNumVertices(g);
	e.values = malloc(e.numNodes * sizeof(double *));
	for (int i = 0; i < e.numNodes; i++) {
		e.values[i] = malloc(e.numNodes * sizeof(double));
	}
	for (int i = 0; i < e.numNodes; i++) {
		for (int j = 0; j < e.numNodes; j++) {
			e.values[i][j] = -1.0;
		}
	}

	// Find the shortest pair for all nodes.
	ShortestPaths sps = FloydWarshall(g);

	// Calculate the number of shortest paths through current edge
	// Which means the number of appearance of current edge in sps.next
	// Determine the edge betweenness in e.values,
	// by looping thro the 2d array.
	for (int i = 0; i < e.numNodes; i++) {
		for (int j = 0; j < e.numNodes; j++) {
			// Determine the path 
			// if there are adjacent and a path exist.
			if (GraphIsAdjacent(g, i, j) == true && sps.next[i][j] != -1) {
				e.values[i][j] = numberOfEdgePasses(i, j, sps, e);
			}
		}
	}

	// Free all memories related to FloydWarshall.
	freeShortestPaths(sps);

	return e;
}

double numberOfEdgePasses(int edgeSrc, int edgeDes, ShortestPaths sps, EdgeValues e) {
	double counterEdgePasses = 0.0;
	for (int i = 0; i < e.numNodes; i++) {
		for (int j = 0; j < e.numNodes; j++) {
			int a = i;
			int b = j;
			// Keep searching until there is no path.
			while (sps.next[a][b] != -1) {
				int k = sps.next[a][b];
				if ((a == edgeSrc && k == edgeDes)) {
					counterEdgePasses++;
					break;
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
	for (int i = 0; i < evs.numNodes; i++) {
		free(evs.values[i]);
	}
	free(evs.values);

}


