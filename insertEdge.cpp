#include"NetTopo.h"

//带权边插入-函数
bool NetTopo::insertEdge(int v1, int v2, int cost)
{
	if (v1 > -1 && v1<maxVertices && v2>-1 && v2 < maxVertices && Edge[v1][v2] == inf)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
};