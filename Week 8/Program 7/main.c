#include <stdio.h>
#include "graph.h"

int main ()
{
	/* change this number to generate different graphs */
	int graphTestNumber = 3; /* permissible values are 1-5 */
	/* switch this to 0 to use BFS */
	int useDFS = 1;

	int i, j;
	Graph g;

	/* set up the graph */
	if(graphTestNumber == 1)
		createGraph1(&g);
	else if(graphTestNumber == 2)
		createGraph2(&g);
	else if(graphTestNumber == 3)
		createGraph3(&g);
	else if(graphTestNumber == 4)
		createGraph4(&g);
	else if(graphTestNumber == 5)
		createGraph5(&g);
	else
	{
		printf("Invalid test number... Quitting");
		return 1;
	}
	printGraph(&g);

	if(useDFS)
		printf("\nComputing reachability using DFS\n");
	else
		printf("\nComputing reachability using BFS\n");

	for(i = 0; i < g.numVertices; ++i)
		for(j = i+1; j < g.numVertices; ++j)
		{
			printf("%c to %c\t\t\t", g.vertexSet[i].label, g.vertexSet[j].label);
			if(useDFS)
				if(DFS(&g, &g.vertexSet[i], &g.vertexSet[j]))
					printf("reachable!\n");
				else
					printf("***UNREACHABLE***\n");
			else
				if(BFS(&g, &g.vertexSet[i], &g.vertexSet[j]))
					printf("reachable!\n");
				else
					printf("***UNREACHABLE***\n");
		}

	return 0;
}
