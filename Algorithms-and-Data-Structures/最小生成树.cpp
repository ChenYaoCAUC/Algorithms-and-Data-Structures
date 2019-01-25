#include <iostream>
using namespace std;
#define N_Max 1002
#define M_Max 3006
#define MaxValue 9999999
 
typedef struct MGraph *PGraph;
struct MGraph
{
    int G[N_Max][N_Max];
    int Nv;
    int Ne;
    int Flag;
};
 
PGraph CreateGraph(int N,int M)
{
    PGraph Graph=new(MGraph);
    Graph->Flag=0;
    Graph->Nv=N;
    Graph->Ne=M;
    for (int i=1; i<=Graph->Nv; ++i)
    {
        for (int k=1; k<=Graph->Nv; ++k)
        {
            Graph->G[i][k]=MaxValue;
            Graph->G[k][i]=MaxValue;
        }
        
    }
    return Graph;
}
 
int FindMin(int LowCost[],int n)
{
    int j,k=0,MinCost=MaxValue;
    for (j=1; j<=n; j++)
    {
        if (LowCost[j]&&LowCost[j]<MinCost)
        {
            MinCost=LowCost[j];
            k=j;
        }
    }
    if (k==0)
    {
        return 0;
    }
	else
    {
        return k;
    }
}
 
void Prim(PGraph Graph,int Parent[])
{
    int LowCost[N_Max];
    for (int i=1; i<=Graph->Nv; ++i)
    {
        LowCost[i]=MaxValue;
    }
    int i,j,k;
    
    for (i=2; i<=Graph->Nv; i++)
    {
        LowCost[i]=Graph->G[1][i];
        Parent[i]=1;
    }
    LowCost[1]=0;
    Parent[1]=-1;
    
    for (i=2;i<=Graph->Nv; ++i)
    {
        k=FindMin(LowCost,Graph->Nv);
        if (k)
        {
            LowCost[k]=0;
            for (j=2; j<=Graph->Nv; ++j)
            {
                if (LowCost[j]&&Graph->G[k][j]<LowCost[j])
                {
                    LowCost[j]=Graph->G[k][j];
                    Parent[j]=k;
                }
            }
        }else
        {
            Graph->Flag=1;
            break;
        }
    }
    
}
 
PGraph BuildGraph(PGraph Graph)
{
    int row=0,lie=0,weight=0;
    for (int i=1; i<=Graph->Ne; ++i)
    {
        cin>>row>>lie>>weight;
        Graph->G[row][lie]=weight;
        Graph->G[lie][row]=weight;
    }
    return Graph;
}
 
int Cost(int A[],PGraph Graph)
{
    int temp=0,cost=0;
    for (int i=2; i<=Graph->Nv; i++)
    {
        temp=A[i];
        cost+=Graph->G[i][temp];
    }
    return cost;
}
 
int main(int argc, const char * argv[])
{
    //Input
    int N=0,M=0,cost=0;
    cin>>N>>M;
    PGraph Graph=CreateGraph(N, M);
    Graph=BuildGraph(Graph);
    
    int Parent[N_Max]={0};
    Prim(Graph, Parent);
    if (Graph->Flag==0)
    {
        cost=Cost(Parent,Graph);
    }
    
    
    if (N==1)
    {
        cout<<'0';
    }
    else
    {
    
        if (Graph->Flag==0)
        {
            cout<<cost;
        }else{
            cout<<"-1";
        }
    }
    return 0;
}

