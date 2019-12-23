#include"NetTopo.h"
//求顶点v到各个顶点的最短路径
void NetTopo::ShortestPath(int v,int dist[],int path[])
{
    int n=numVertices;
    bool *S=new bool[n];//最短路径顶点集
    //int i,j,k;
    int w,min;
    for(int i=0;i<n;++i)
    {
        dist[i]=getWeight(v,i);//最短路径长度数组初始化
        S[i]=false;
        if(i!=v&&dist[i]<inf)
            path[i]=v;  //保存该顶点的前一个顶点
        else
            path[i]=-1;
    }
    S[v]=true;  //将顶点v加入顶点集
    dist[v]=0;
    for(int i=0;i<n-1;i++)
    {
        min=inf;
        int u=v;
        //选取不在最短路径顶点集S中的顶点
        for(int j=0;j<n;j++)
        {
            if(!S[j]&&dist[j]<min)
            {
                u=j;min=dist[j];
            }
        }
        S[u]=true;
        for(int k=0;k<n;++k)
        {
            w=getWeight(u,k);
            //用到顶点u的最短路径长度去更新其他未找到最短路径长度的点
            if(!S[k]&&w<inf&&dist[u]+w<dist[k])
            {
                dist[k]=dist[u]+w;//更新最短路径长度
                path[k]=u;  //修改到k的最短路径
            }
        }
    }
}
