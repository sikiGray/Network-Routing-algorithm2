#include<iostream>
#include<fstream>
#include"NetTopo.h"
using namespace std;
int main(void)
{
    int i,j,cost;
    int t,v;
    int v1,v2;
    int dist[100];
    int path[100];
    NetTopo G;
    ifstream fin;

    cout<<"\t\t1、从文件导入网络拓扑信息"<<endl<<endl;
    cout<<"\t\t2、插入新的顶点"<<endl<<endl;
    cout<<"\t\t3、插入新的边"<<endl<<endl;
    cout<<"\t\t4、删除指定顶点"<<endl<<endl;
    cout<<"\t\t5、删除指定边"<<endl<<endl;
    cout<<"\t\t6、输出指定路由器的路由表"<<endl<<endl;
    while(1)
    {
        int choice;
        cout<<"请输入选项：";
        cin>>choice;
        switch(choice)
        {
        case 1:
            fin.open("Vertex.txt",ios::in);
            //cout<<'*'<<endl;
            while(fin>>i)
            {
                G.insertVertex(i);
                //cout<<i<<endl;
            }

            fin.close();
            fin.open("NetTopo.txt",ios::in);
            while(fin>>i>>j>>cost)
            {
                G.insertEdge(G.getVertexPos(i),G.getVertexPos(j),cost);
                //cout<<'*'<<endl;
            }

            fin.close();
            cout<<"导入成功"<<endl;
            break;
        case 2:
            cout<<"请输入新的顶点信息：";
            cin>>v;
            if(G.insertVertex(v))
                cout<<"插入成功！"<<endl;
            else
                cout<<"插入失败！"<<endl;
                break;

        case 3:
            cout<<"请输入要添加的边的两个顶点与权值：";
            cin>>v1>>v2>>cost;
            G.insertEdge(G.getVertexPos(v1),G.getVertexPos(v2),cost);
            break;
        case 4:
            cout<<"请输入要删除的顶点：";
            cin>>v;
            if(G.removeVertex(G.getVertexPos(v)))
                cout<<"插入成功！"<<endl;
            else
                cout<<"插入失败！"<<endl;
        case 5:
            cout<<"请输入要删除的边的两个顶点："<<endl;
            cin>>v1>>v2;
            if(G.removeEdge(G.getVertexPos(v1),G.getVertexPos(v2)))
                cout<<"删除成功！"<<endl;
            else
                cout<<"删除失败！"<<endl;
        case 6:
            cout<<"请输入要查询路由表的路由器号：";
            cin>>t;
            v=G.getVertexPos(t);
            if(v==-1)
            {
                cout<<"不存在此路由器"<<endl;
                break;
            }
            G.ShortestPath(v,dist,path);
            G.printRoutingTable(v,dist,path);
            break;
        }
    }
}
