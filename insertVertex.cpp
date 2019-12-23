#include"NetTopo.h"

//顶点插入函数
bool NetTopo::insertVertex(int v)
{
    for(int i=0;i<numVertices;++i)
    {
        if(VerticesList[i]==v)
            return false;
    }
	if (numVertices == maxVertices)//路由集合已达到最大，不能再插入
		return false;
	VerticesList[numVertices] = v;//结点列表更新
	++numVertices;//结点数增加
};
