#include"NetTopo.h"

//返回边(v1,v2)上的权值，若存在顶点不在图中，则函数返回0
int NetTopo::getWeight(int v1, int v2)//参数：序号（合法性在getVertexPos()和mian()中检查）
{
	if (v1 != -1 && v2 != -1)
		return Edge[v1][v2];//无向图
	return 0;
};