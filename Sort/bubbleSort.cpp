#include<iostream>
using namespace std;
void bubbleSort(int arr[],int n)
{
	int i,j,tmp;
	for(i=0;i<n-1;i++)
	{
		for(j=1;j<n;j++)
		{
			if(arr[j]<arr[j-1])
			{
				tmp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=tmp;
			}
		}
	}
}

void bubbleSort_1(int arr[],int n)
{
	int i,flag,tmp;
	do{
		flag=0;
		for(i=0;i<n-1;i++)
		{
			if(arr[i]>arr[i+1]){
				tmp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
				flag=i+1;
			}
		}
		n=flag;
	}while(flag);
}
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
		printf(" ");
	}
	printf("\n");
}
int main()
{
	printf("How many numbers do you want to sort:");
	int n,arr[1000];
	scanf("%d",&n);
	printf("Plaese enter the numbers you want to sort:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubbleSort_1(arr,n);
	printArray(arr,n);
	return 0;
}
