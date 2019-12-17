#include"NetTopo.h"

//带权边插入-函数
bool NetTopo::insertEdge(int v1, int v2, int cost)
{
	if (v1 > -1 && v1<numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] == inf)//检查“v1—v2”的合法性：1、v1是路由集合里的路由集合；2、“v1—v2”边长必须是目前不可达的，如果已经可达就无法修改。
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;//无向图
		numEdges++;//边的个数增加
		return true;//修改成功
	}
	else
		return false;//修改失败
};