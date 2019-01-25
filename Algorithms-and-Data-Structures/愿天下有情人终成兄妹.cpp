#include<iostream>
using namespace std;
struct TreeNode{
	string Id;
	char sex;
	string faId;
	string MoId;
	TreeNode* father;
	TreeNode* mother;
};
struct IdDouble{
	string Id1;
	string Id2;
};
bool IfSameSex(TreeNode* a,TreeNode* b)
{
	if(a->sex==b->sex)
	return true;
	else
	return false;
}
void Tree(TreeNode *p[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[i]->faId==p[j]->Id)
			{
				p[i]->father=p[j];
			}
			if(p[i]->MoId==p[j]->Id)
			{
				p[i]->mother=p[j];
			}
		}
	}
}
bool IfInWuFu(TreeNode* a,TreeNode* b)
{
	if(a->mother==b->mother||a->father==b->father||a->mother->mother==b->mother->mother
	||a->father->father==b->father->father||a->mother->mother->mother==b->mother->mother->mother
	||a->father->father->father==b->father->father->father
	||a->mother->mother->mother->mother==b->mother->mother->mother->mother||a->father->father->father->father==b->father->father->father->father)
		return true;
	else
		return false;
}
int main()
{
	int n,m;
	string ID1;
	string ID2;
	int temp1=-1;
	int temp2=-1;
	cin>>n;
	TreeNode *p[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new TreeNode;
		cin>>p[i]->Id;
		cin>>p[i]->sex;
		cin>>p[i]->faId;
		cin>>p[i]->MoId;
	}
	Tree(p,n);
	cin>>m;
	IdDouble *q[m];
	for(int j=0;j<m;j++)
	{
		q[j]=new IdDouble;
		cin>>q[j]->Id1;
		cin>>q[j]->Id2;		
	}
	for(int k=0;k<m;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(q[k]->Id1==p[i]->Id)
			{
				temp1=i;
			}
			if(q[k]->Id2==p[i]->Id)
			{
				temp2=i;
			}
			if(temp1!=-1&&temp2!=-1)
				break;
		}
		if(IfSameSex(p[temp1],p[temp2]))
		{
			cout<<"Never Mind"<<endl;;
		}
		else
		{
			if(IfInWuFu(p[temp1],p[temp2]))	
			{
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		
	}
	return 0;
	
}
