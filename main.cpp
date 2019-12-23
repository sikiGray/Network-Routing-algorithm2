#include<iostream>
#include<fstream>
#include<windows.h>
#include"NetTopo.h"
using namespace std;
void menu();
int main(void)
{
    int i,j,cost;
    int t,v;
    int v1,v2;
    int dist[100];
    int path[100];
    NetTopo G;
    ifstream fin;


    while(1)
    {
        cout << "同步测试 2" << endl;
        menu();
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
            cout<<endl;
            cout<<"         导入成功！"<<endl<<endl;
            //cin>>v;
            //cout<<G.getDegree(G.getVertexPos(v))<<endl;
            system("pause");
            system("cls");
            break;
        case 2:
            cout<<"请输入新的顶点信息：";
            cin>>v;
            if(G.insertVertex(v))
            {
                cout<<endl;
                cout<<"         插入成功！"<<endl<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"         插入失败！"<<endl<<endl;
            }
            system("pause");
            system("cls");
            break;
        case 3:
            cout<<"请输入要添加的边的两个顶点与权值：";
            cin>>v1>>v2>>cost;
            G.insertEdge(G.getVertexPos(v1),G.getVertexPos(v2),cost);

            cout<<endl;
            cout<<"         添加成功！"<<endl<<endl;
            system("pause");
            system("cls");
            break;
        case 4:
            cout<<"请输入要删除的顶点：";
            cin>>v;
            if(G.removeVertex(G.getVertexPos(v)))
            {
                cout<<endl;
                cout<<"         删除成功！"<<endl<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"         删除失败！"<<endl<<endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            cout<<"请输入要删除的边的两个顶点：";
            cin>>v1>>v2;

            if(G.removeEdge(G.getVertexPos(v1),G.getVertexPos(v2)))
            {
                cout<<endl;
                cout<<"         删除成功！"<<endl<<endl;
            }
            else
            {
                cout<<endl;
                cout<<"         删除失败！"<<endl<<endl;
            }

            system("pause");
            system("cls");
            break;
        case 6:
            cout<<"请输入要查询路由表的路由器号：";
            cin>>t;
            v=G.getVertexPos(t);
            if(v==-1)
            {
                cout<<"         不存在此路由器！"<<endl;
                system("pause");
                system("cls");
                break;
            }
            G.ShortestPath(v,dist,path);
            G.printRoutingTable(v,dist,path);

            system("pause");
            system("cls");
            break;
        }
    }
}
