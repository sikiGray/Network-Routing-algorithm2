#include"NetTopo.h"

//删除结点v及相关的边
bool NetTopo::removeVertex(int v)
{
	if (v<0 || v>numVertices)//顶点v不存在图中
		return false;
	if (numVertices == 1)//当只剩一个顶点时，不进行删除
		return false;
	VerticesList[v] = VerticesList[numVertices - 1];//首先从顶点表中删除该顶点

	//重新计算当前拓扑中的边数（减去少掉的边）
	for (int i = 0;i < numVertices;++i)
	{
		if (Edge[i][v] > 0 && Edge[i][v] < inf)
			numEdges--;
	}
	//使用最后一列填补第v列
	for (int i = 0;i < numVertices;++i)
		Edge[i][v] = Edge[i][numVertices - 1];
	numVertices--;
	//使用最后一行填补第v行
	for (int i = 0;i < numVertices;++i)
		Edge[v][i] = Edge[numVertices][i];
	return true;
};