#include"NetTopo.h"

//��Ȩ�߲���-����
bool NetTopo::insertEdge(int v1, int v2, int cost)
{
	cout << "������" << endl;
	if (v1 > -1 && v1<numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] == inf)//��顰v1��v2���ĺϷ��ԣ�1��v1��·�ɼ������·�ɼ��ϣ�2����v1��v2���߳�������Ŀǰ���ɴ�ģ�����Ѿ��ɴ���޷��޸ġ�
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;//����ͼ
		numEdges++;//�ߵĸ�������
		return true;//�޸ĳɹ�
	}
	else
		return false;//�޸�ʧ��
};