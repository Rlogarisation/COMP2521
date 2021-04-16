// Floyd Warshall ADT interface
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "FloydWarshall.h"
#include "Graph.h"

/**
 * Finds all shortest paths between all pairs of nodes.
 * 
 * The  function  returns  a 'ShortestPaths' structure with the required
 * information:
 * - the number of vertices in the graph
 * - distance matrix
 * - matrix of intermediates (see description above)
 */
ShortestPaths FloydWarshall(Graph g) {
	// Implement the framework for ShortestPaths.
	ShortestPaths sps;
	sps.numNodes = GraphNumVertices(g);


	// Implement sps.dist:
	// An 2d array which shows shortest distance between any two vertices.
	sps.dist = malloc(sps.numNodes * sizeof(int *));
	// Implement sps.next:
	// An 2d array which shows next vertex from given vertex to des.
	sps.next = malloc(sps.numNodes * sizeof(int *));
	for (int v = 0; v < sps.numNodes; v++) {
		sps.dist[v] = malloc(sps.numNodes * sizeof(int));
		sps.next[v] = malloc(sps.numNodes * sizeof(int));
	}
	// Set the distance between all as infinity for now.
	// Set the whole array fill with -1 for now.
	for (int i = 0; i < sps.numNodes; i++) {
		for (int j = 0; j < sps.numNodes; j++) {
			sps.dist[i][j] = INFINITY;
			sps.next[i][j] = -1;
		}
	}
	// First, fill in the value of dist[v][v] itself = 0.
	for (int v = 0; v < sps.numNodes; v++) {
		sps.dist[v][v] = 0;
	} 
	// Second, fill in the neighbour distance.
	for (int v = 0; v < sps.numNodes; v++) {
		AdjList ListOutIncident = GraphOutIncident(g, v);
		while (ListOutIncident != NULL) {
			sps.dist[v][ListOutIncident->v] = ListOutIncident->weight;
			// Assume in next: node 1 to node 2 will have a next of node 2.
			sps.next[v][ListOutIncident->v] = ListOutIncident->v;
			
			ListOutIncident = ListOutIncident->next;
		}
	}
	// Last step, search the shortest path between inter-vertices.
	for (int k = 0; k < sps.numNodes; k++) {
		for (int i = 0; i < sps.numNodes; i++) {
			for (int j = 0; j < sps.numNodes; j++) {
				if (sps.dist[i][j] > sps.dist[i][k] + sps.dist[k][j]
				&& sps.dist[i][k] + sps.dist[k][j] > 0) {
					sps.dist[i][j] = sps.dist[i][k] + sps.dist[k][j];
					sps.next[i][j] = k;
				}
			}
		}
	}

	return sps;
}

/**
 * This  function  is  for  you to print out the ShortestPaths structure
 * while you are debugging/testing your implementation. 
 * 
 * We will not call this function during testing, so you may  print  out
 * the  given  ShortestPaths  structure in whatever format you want. You
 * may choose not to implement this function.
 */
void showShortestPaths(ShortestPaths sps) {
	for (int i = 0; i < sps.numNodes; i++) {
		for (int j = 0; j < sps.numNodes; j++) {
			if (sps.dist[i][j] != INFINITY) {
				printf("From %d to %d has the shortest distance of %d\n", 
				i, j, sps.dist[i][j]);
			}
			
		}
	}
	for (int i = 0; i < sps.numNodes; i++) {
		for (int j = 0; j < sps.numNodes; j++) {
			if (sps.next[i][j] != -1) {
				printf("From %d to %d has the next vertex of %d\n", 
				i, j, sps.next[i][j]);
			}
			
		}
	}
}

/**
 * Frees  all  memory associated with the given ShortestPaths structure.
 * We will call this function during testing, so you must implement it.
 */
void freeShortestPaths(ShortestPaths sps) {
	// Free rows for both dist and next first.
	for (int i = 0; i < sps.numNodes; i++) {
		free(sps.dist[i]);
		free(sps.next[i]);
	}
	// Free dist and next itself.
	free(sps.dist);
	free(sps.next);
}

