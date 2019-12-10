#include"NetTopo.h"

//给出顶点在顶点表中的下标
int NetTopo::getVertexPos(int v)//参数：IP
{
	for (int i = 0;i < numVertices;++i)
	{
		if (VerticesList[i] == v)
			return i;//返回IP在路由集合中的序号
	}
	return -1;//没找到，失败
};