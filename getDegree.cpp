#include"NetTopo.h"
int NetTopo::getDegree(int v)
{
    int d=0;
    for(int i=0;i<numVertices;++i)
    {
        if(Edge[v][i]>0&&Edge[v][i]<inf)
            ++d;
    }
    return d;
}
