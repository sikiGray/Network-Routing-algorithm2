#include"NetTopo.h"

//删除边(v1,v2)
bool NetTopo::removeEdge(int v1, int v2)
{
	if (v1 > -1 && v1<maxVertices && v2>-1 && v2 < maxVertices && Edge[v1][v2]>0 && Edge[v1][v2] < inf)//检查输入边的合法性：1、结点v1、v2在路由集合内；2、v1和v2之间是可达的。
	{
		Edge[v1][v2] = Edge[v2][v1] = inf;//将边的权重改为不可达
		numEdges--;//边的个数减少
		return true;//修改成功
	}
	else
		return false;//修改失败
};