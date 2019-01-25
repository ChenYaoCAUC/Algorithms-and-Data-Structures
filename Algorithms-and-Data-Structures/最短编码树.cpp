#include<iostream>
#include<stdlib.h> 
using namespace std;
template<class T>
class HuffeManTreeNode{
private:
	T weight;
	HuffeManTreeNode *Left;
	HuffeManTreeNode *Right;
public:
	void SetLeft(HuffeManTreeNode *left){
	this->Left=left;
	}
	void SetRight(HuffeManTreeNode *right){
	this->Right=right;
	}
	void SetWeight(T weight){
	this->weight=weight;
	}
	T GetWeight()
	{
		return weight;
	}
	HuffeManTreeNode* GetLeft(){
		return Left;
	}
	HuffeManTreeNode* GetRight(){
		return Right;
	}
};
template<class T>
class HuffeManTree{
	void HuffeManTree(T *num,int n){
		T tempLeft=0;
		T tempRight=0;
		int flag=0;
	    tempLeft=num[0]+num[1];
		HuffeManTreeNode *Tree;
		Tree->SetLeft(&num[0]);
		Tree->SetRight(&num[1]);
		Tree->SetWeight(tempLeft);
		for(int i=2;i<n;i++)
		{
			while(i+1<n)
			{
				if((num[i]+num[i+1])<=tempLeft)
				{
					flag=1;
					tempLeft=num[i]+num[i+1];
					HuffeManTreeNode *TreeLeft;
					TreeLeft->SetLeft(NULL);
					TreeLeft->SetRight(NULL);
					TreeLeft->SetWeight(tempLeft);
					i++;
				} 
				else
				{
					if(flag==0)
					{
						tempRight=tempLeft;
					}
					HuffeManTreeNode *TreeRight;
					TreeRight->SetLeft(NULL);
					TreeRight->SetRight(TreeLeft);
					tempRight=tempRight+num[i];
					TreeRight->SetWeight(tempRight);
				}
			}
			if(i==n-1)
			{
				if(tempRight!=0)
				{
					HuffrManTreeNode *Tree3;
					Tree->SetLeft(TreeLeft);
					Tree->SetRight(TreeRight);
					Tree->SetWeight(tempRight+tempLeft);
					}	
			}	
		}
	}
	
};
int main()
{
	int *num;
	int n,m;
	cin>>n;
	num=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		cin>>m;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			int temp=num[j];
			num[j]=num[j+1];
			num[j+1]=temp;
		}
	}
	HuffeManTree(num,n);	
}

