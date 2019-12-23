#include"NetTopo.h"
//打印路由表
void NetTopo::printRoutingTable(int v,int dist[],int path[])
{
    cout<<endl;
    if(getDegree(v)==0)
    {
        cout<<"该路由器已从网络中断开！"<<endl<<endl;
        return;
    }
    cout<<"路由器"<<VerticesList[v]<<"的路由表如下："<<endl;
    cout<<"\t目的网络"<<"\t下一跳"<<endl;
    for(int i=0;i<numVertices;++i)
    {
        if(i!=v&&getDegree(i)>0)
        {
            int k=i;
            while(path[k]!=v)
            {
                k=path[k];
            }
            cout<<"\t  "<<VerticesList[i]<<"\t\t  "<<VerticesList[k]<<endl;
        }
        else if(i==v)
        {
            cout<<"\t  "<<VerticesList[i]<<"\t\t  "<<"直接"<<endl;
        }
    }
}
