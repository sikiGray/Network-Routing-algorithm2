//构造函数
NetTopo::NetTopo(int sz)
{
    maxVertices=sz;//设置最大顶点数
    numVertices=0;//当前定点数设置为0
    numEdges=0;//当前边数设置为0
    VerticesList=new int[maxVertices];//建立顶点表数组

    Edge=(int **)new int*[maxVertices];//建立邻接矩阵
    for(int i=0;i<maxVertices;++i)
        Edge[i]=new int[maxVertices];
    //邻接矩阵初始化
    for(int i=0;i<maxVertices;++i)
        for(int j=0;j<maxVertices;++j)
    {
        Edge[i][j]=((i==j)? 0:inf);
    }
}
