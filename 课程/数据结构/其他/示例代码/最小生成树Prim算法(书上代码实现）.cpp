#include<iostream>
using namespace std;
#define MAXVERTEXNUM 100

class Graph{
	int  VertexNum;		// ������
	char Vertex[MAXVERTEXNUM];// ��������
	bool visited[MAXVERTEXNUM];
	int  AdjMatrix[MAXVERTEXNUM][MAXVERTEXNUM];					// �ڽӾ���
	
public:
	Graph()	// ����ͼ
	{
		int  i, j;
		cin >> VertexNum;	//���붥��������Ŀ
/*		for (i=0; i<VertexNum; i++)
			cin >> Vertex[i]; 	//���붥��*/
		for (i=0; i<VertexNum; i++) {
			for (j=0; j<VertexNum; j++) {
				cin >> AdjMatrix[i][j];//���������ڽӾ���
			}
		}
	} 

	void Prim(char StartVexChar){
		int i, j, m, StartVex, CurrentVex,minW=1000;
		bool S[MAXVERTEXNUM];
		for(i=0;i<VertexNum;i++)
			S[i]=false;
		for (i=0; i<VertexNum; i++) 		// �ҵ���ʼ��������
			if (Vertex[i] == StartVexChar) {
				StartVex = i; 
				break;	
			}
		S[StartVex]=true;
		m=1;
		while(m<VertexNum){
			for(i=0;i<VertexNum;i++){
				if(S[i])
					for(j=0;j<VertexNum;j++){
						if(!S[j]&&AdjMatrix[i][j]>0&&AdjMatrix[i][j]<minW){
							minW=AdjMatrix[i][j];
							StartVex=i;
							CurrentVex=j;
						}
					}
			}
			S[CurrentVex]=true;
			cout<<Vertex[StartVex]<<" "<<Vertex[CurrentVex]<<" "<<AdjMatrix[StartVex][CurrentVex]<<endl;
			m++;
			minW=1000;
		}
	}


	void minspantree_prim(int v)
	{
		int k,j,i;
		int low=10000;
		struct {
			int adj;
			int lowcost;
		}closedge[MAXVERTEXNUM];
		k=v;
		closedge[v].lowcost=0;
		for(j=0;j<VertexNum;j++)//��ʼ��
			if(j!=k) {
				closedge[j].adj=k;
				if (AdjMatrix[k][j]==0 && k!=j)
					closedge[j].lowcost=10000;
				else
					closedge[j].lowcost=AdjMatrix[k][j];
			}
		for(i=1;i<VertexNum;++i)
		{   
			low=10000;
			for(j=0;j<VertexNum;j++)
				if (low>closedge[j].lowcost && closedge[j].lowcost!=0)
				{
					low=closedge[j].lowcost;
					k=j;
				}
			cout<<closedge[k].adj<<" "<<k<<" "<<closedge[k].lowcost<<endl;
			closedge[k].lowcost=0;
			
			for(j=0;j<VertexNum;j++)
			{
				if (closedge[j].lowcost>AdjMatrix[k][j] && AdjMatrix[k][j]!=0 && k!=j)
				{
					closedge[j].adj=k;
					closedge[j].lowcost=AdjMatrix[k][j];
				}
			}
		}
	}

};

int main(){
	Graph g;
	g.minspantree_prim(0);
	return 0;
}
