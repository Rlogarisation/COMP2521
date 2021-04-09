// Write a function to check whether a path, 
// supplied as an array of Edges is an Euler path. 

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

// check whether a given path is a Euler path
bool isEulerPath(Graph g, Edge e[], int nE)
{
	assert(g != NULL);

	// includes all edges
	if (g->nE != nE)
		return false;

	// edges are actually in the graph
	for (int i = 0; i < nE; i++)
		if (g->edges[e[i].v][e[i].w] == 0)
			return false;

	// is actually a path
	for (int i = 0; i < nE - 1; i++)
		if (e[i].w != e[i + 1].v)
			return false;

	// includes edges exactly once
	for (int i = 0; i < nE; i++) {
		for (int j = i + 1; j < nE; j++) {
			if (e[i].v == e[j].v && e[i].w == e[j].w) return false;
			if (e[i].v == e[j].w && w[i].w == e[j].v) return false;
		}
	}
	
	return true;
}