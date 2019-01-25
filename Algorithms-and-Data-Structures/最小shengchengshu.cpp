#include<iostream>
#include<queue>
using namespace std;
class Edge{
	public:
		int from,to,weight;
		Edge()
		{
			from=-1;
			to=-1;
			weight=0;
		}
		Edge(int f,int t,int w):from(f),to(t),weight(w){}
};
class Graph{
	public:
		int numEdge;
		int numVertex;
		int *Mark;
		int *Indegree;
		Graph(int NumVert){
			numVertex=NumVert;
			numEdge=0;
			Indegree=new int[numVertex];
			Mark=new int[numVertex];
			for(int i=0;i<numVertex;i++)
			{
				Mark[i]=-1;
				Indegree[i]=0;
			}
		} 
		~Graph(){
			delete []Mark;
			delete []Indegree;
		} 
		int VerticesNum(){
			return numVertex;
		}
		int EdgesNum(){
			return numEdge;
		}
		bool IsEdge(Edge oneEdge){
			if(oneEdge.weight>0&&oneEdge.to>=0&&oneEdge.from>=0)
				return true;
			else
				return false;
		}
};
class Graphm:public Graph{
	private:
		Edge e;
		int **matrix;
	public:
		Graphm(int NumVert):Graph(NumVert){
			int i,j;
			matrix=(int **)new int*[numVertex];
			for(i=0;i<numVertex;i++)
				matrix[i]=new int[numVertex];
			for(i=0;i<numVertex;i++)
				for(j=0;j<numVertex;j++)
					matrix[i][j]=0;
		}
		~Graphm(){
			for(int i=0;i<numVertex;i++)
				delete[] matrix[i];
			delete []matrix;
		}
		int GetWeight(Edge e)
		{
			return e.weight;
		}
		Edge FirstEdge(int oneVertex){
			Edge myEdge;
			myEdge.from=oneVertex;
			for(int i=0;i<numVertex;i++)
			{
				if(matrix[oneVertex][i]!=0)
				{
					myEdge.to=i;
					myEdge.weight=matrix[oneVertex][i];
					break;
				}
			}
			return myEdge;
		}
		Edge NextEdge(Edge preEdge){
			Edge myEdge;
			myEdge.from=preEdge.from;
			if(preEdge.to<numVertex)
			{
				for(int i=preEdge.to+1;i<numVertex;i++)
				{
					if(matrix[preEdge.from][i]!=0){
						myEdge.to=i;
						myEdge.weight=matrix[preEdge.from][i];
						break;
					}
				}
			}
			return myEdge;
		}
		int FromVertex(Edge e)
	    {
	    	return e.from;
		}
		int ToVertex(Edge e)
		{
			return e.to;
		}
		void setEdge(int from,int to,int weight){
			if(matrix[from][to]<=0){
				numEdge++;
				Indegree[to]++;
			}
			matrix[from][to]=weight;
		}
		void delEdge(int from,int to){
			if(matrix[from][to]>0){
				numEdge--;
				Indegree[to]--;
			}
			matrix[from][to]=0;
		}
};
int Prim(Graphm& G,int s)
{
	int sum=0;
	int minWeight;
	int tempWeight;
	Edge First;
	for(int i=1;i<G.VerticesNum();i++)
	{
		if(G.IsEdge(G.FirstEdge(s)))
		{
		    First=G.FirstEdge(s);
			minWeight=G.GetWeight(First);
			G.Mark[s]=0;
		}
		else
			return -1;
		while(G.IsEdge(G.NextEdge(First)))
		{
			tempWeight=G.GetWeight(G.NextEdge(First));
			if(tempWeight<minWeight)
			{
				First=G.NextEdge(First);
				int temp=tempWeight;
				tempWeight=minWeight;
				minWeight=temp;
			}
		}
		sum=sum+minWeight;		
		s=G.ToVertex(First);
		G.Mark[s]=0;
	}
	return s;		
 } 
 int main()
 {	
 	int m,n;
 	int a,b,w;
 	cin>>m>>n;
 	Graphm G(m);
 	for(int i=0;i<n;i++)
 	{
 		cin>>a>>b>>w;
		 G.setEdge(a,b,w);	
	 }
	 cout<<Prim(G,a);
 	
 }
/*void Kruskal(Graphm &G,Edge *&MST){
	ParTree<int> A(G.VerticesNum());//等价类 
	MinHeap<Edge>H(G.EdgesNum());//最小堆 
	MST=new Edge[G.VerticesNum()-1];
	int MSTtag=0;//最小生成边计数 
	bool heapEmpty;
	for(int i=0;i<G.VerticesNum();i++)//将图的所有边插入到最小堆H中 
	{
		for(Edge e=G.FirstEdge(i);G.IsEdge(e);i++)
		{
			if(G.FromVertex(e)<G.ToVertex(e))//对于无向图，防止重复插入边 
				H.Insert(e);
		}
	}
	int EquNum=G.VerticesNum();//开始n个顶点分别作为一个等价类 
	while(EquNum>1)//当等价类的个数大于1时合并等价类 
	{
		heapEmpty=H.isEmpty;
		if(!heapEmpty)
			Edge e=H.RemoveMin();//获得一条边的最小权 
		if(heapEmpty||e.weight==INFINITY){
			delete[] MST;//不存在最小生成树 
			MST=NULL;
			return;
		}
	}
	int from=G.FromVertex(e);//记录该边的信息 
	int to=G.ToVertex(e);
	if(A.Different(from,to)){//边e的两个顶点不在一个等价类将边e的两个顶点的等价类合为一个 
		A.Union(from,to);
	}
	AddEdgetoMST(e,MST,MSTtag++);//将边e 加到 MST
	EquNum--;//等价类的个数减一 
}*/ 
