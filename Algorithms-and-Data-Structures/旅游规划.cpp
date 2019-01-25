#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef struct graphnode *Graph;
int s,d;
struct graphnode
{
	int Nv,Ne;
	int G[501][501];
	int P[501][501];
};
void Insert(Graph g,int x,int y,int w,int z)
{
	g->G[x][y]=w;
	g->G[y][x]=w;
	g->P[x][y]=z;
	g->P[y][x]=z; 
}
Graph Create()
{
	int m,n;
	cin>>n>>m>>s>>d;
	Graph g=(Graph)malloc(sizeof(struct graphnode));
	g->Nv=n;
	g->Ne=m;
//	memset(g->G,65535,sizeof(g->G));
//	memset(g->P,65535,sizeof(g->P));
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		g->G[i][j]=65535;
    		g->P[i][j]=65535;
		}
	}
	while(m--)
	{
		int S,D,L,M;
		cin>>S>>D>>L>>M;
		Insert(g,S,D,L,M);
	}
	return g;
}
void Dijkstra(Graph g,int v0,int *D,int *PP)
{
	int flag[501],mm,i,j,k,mo;
	for(i=0;i<g->Nv;i++)
	{
		flag[i]=0;
		D[i]=g->G[v0][i];
		PP[i]=g->P[v0][i];
	}
	D[v0]=0;
	flag[v0]=1;
	for(i=0;i<g->Nv;i++)
	{
		mm=65535;
		for(j=0;j<g->Nv;j++)
		{
			if(!flag[j])
			if(D[j]<mm)
			{
				mm=D[j];
				mo=PP[j];
				k=j;
			}
		}
		if(mm<65535)
		{
			flag[k]=1;
		}
		else
			break;
		for(int p=0;p<g->Nv;p++)
		{
			if(!flag[p]&&mm+g->G[k][p]<D[p])
			{
				D[p]=mm+g->G[k][p];
				PP[p]=mo+g->P[k][p];
			}
			else
				if(!flag[p]&&mm+g->G[k][p]==D[p]&&mo+g->P[k][p]<PP[p])
				{
					PP[p]=mo+g->P[k][p];
				}
		}
	}
}
int main()
{
	Graph g=Create();
	int c1[505],c2[505];
	Dijkstra(g,s,c1,c2);
	cout<<c1[d]<<" "<<c2[d]<<endl;
	return 0;
}

