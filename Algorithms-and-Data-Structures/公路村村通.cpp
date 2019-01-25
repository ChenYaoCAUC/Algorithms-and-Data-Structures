#include<iostream>
using namespace std;
#define MaxValue 9999999
class Edge {
public:
	int from, to, weight;
	Edge()
	{
		from = -1;
		to = -1;
		weight = 0;
	}
	Edge(int f, int t, int w) :from(f), to(t), weight(w) {}
};
class Graph {
public:
	int numEdge;
	int numVertex;
	int *Mark;
	Graph(int NumVert) {
		numVertex = NumVert;
		numEdge = 0;
		Mark = new int[numVertex+1];
		for (int i = 1; i <= numVertex; i++)
		{
			Mark[i] = -1;
		}
	}
	~Graph() {
		delete[]Mark;
	}
};
class Graphm :public Graph {
private:
	int **matrix;
	int min,flag,f;
public:
	Graphm(int NumVert) :Graph(NumVert) {
		int i, j;
		matrix = (int **)new int*[numVertex];
		for (i = 1; i <= numVertex; i++)
			matrix[i] = new int[numVertex];
		for (i = 1; i <= numVertex; i++)
			for (j = 1; j <= numVertex; j++)
				matrix[i][j] = MaxValue;
	}
/*	~Graphm() {
		for (int i = 0; i < numVertex; i++)
			delete[] matrix[i];
		delete[]matrix;
	}*/
	void setEdge(int from, int to, int weight) {
		matrix[from][to] = weight;
		matrix[to][from] = weight;
	}
	int FindMin(int a)
	{
		int i,j;
		min = -1;
		for (j = 1; j <= numVertex; j++)
		{
			if (matrix[a][j] == MaxValue || Mark[j] != -1)
				continue;
			else
			{
				min = matrix[a][j];
				f = j;
				break;
			}
		}
		if (min == -1)
			return -1;
		for (i = j+1; i <= numVertex; i++)
		{
			if (matrix[a][i] == MaxValue || Mark[i] != -1)
				continue;
			if (matrix[a][i] < min)
			{ 
				min = matrix[a][i];
				f = i;
			}
		}
		return f;
	}
	int Money(int a)
	{
		Mark[a] = 0;
		flag = FindMin(a);
		if (flag == -1)
			return -1;
		int sum,i;
		sum = min;
		for (int i = 2; i < numVertex; i++)
		{
			Mark[flag] = 0;
			flag = FindMin(flag);
			if (flag == -1)
				return -1;
			sum = sum + min;
		}
		Mark[flag] = 0;
		for ( i = 1; i <= numVertex; i++)
		{
			if (Mark[i] == -1)
				break;
		}
		if (i > numVertex)
			return sum;
		else
			return -1;
	}

};

int main()
{
	int m, n, a, b, c;
	cin >> m >> n;
	Graphm G(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		G.setEdge(a, b, c);
	}

	cout << G.Money(1);
}
