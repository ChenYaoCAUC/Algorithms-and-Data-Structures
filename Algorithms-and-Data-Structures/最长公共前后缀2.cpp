#include<iostream>
#include <cstring>
using namespace std;
void getNext(char p[],int *next){
	int len=strlen(p);
	next[0]=0;
	int i=0,j=0;
	for(j=1;j<len;j++)
	{
		while(p[i]!=p[j]&&i>0)
		
			i=next[i-1];
			if(p[i]==p[j]){
				i++;
				next[j]=i;
			}
			else{
				next[j]=0;
			}
		
	}
}
int main(){
	char p[100000];
	int i;
	int next[100000];
	cin>>p;
	int len=strlen(p);
	getNext(p,next);
	for( i=0;i<len-1;i++)
	{
		cout<<next[i]<<" ";
	}
	cout<<next[len-1];
	return 0;
}
