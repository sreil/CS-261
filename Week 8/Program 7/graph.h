/*********************************************************************
** Program Filename: graph.h
** Author: Given file
** Date: August 10, 2015
** Description: header for graph
** Input: none
** Output: none
*********************************************************************/

#ifndef GRAPH_DEFINED
#define GRAPH_DEFINED 1

struct Vertex {
	char label;
	int isVisited; /* Use this boolean to remember where you have been */

	int numNeighbors;
	struct Vertex** neighbors; /* array of pointers to Vertex which are adjacent to THIS */
};
typedef struct Vertex Vertex;

struct Graph {
	int numEdges;
	int numVertices;
	Vertex* vertexSet; /* Array of Vertex which store the structure of the graph*/
};
typedef struct Graph Graph;

/* some functions to create various graphs for testing */
void createGraph1(Graph* g);
void createGraph2(Graph* g);
void createGraph3(Graph* g);
void createGraph4(Graph* g);
void createGraph5(Graph* g);

/* utilities to construct and view graphs */
void setupVertices(Graph* g);
void setupEdge(Graph *g, Vertex* first, Vertex* second);
void printGraph(Graph* g);

/* utilities to help analyze graph structure*/
int isAdjacent(Vertex* firstVert, Vertex* secondVert);

/* search related functions */
void clearVisited(Graph* g);
int DFS(Graph* g, Vertex* source, Vertex* destination);
int DFSRecursive(Graph* g, Vertex* source, Vertex* destination);
int BFS(Graph* g, Vertex* source, Vertex* destination);

#endif
