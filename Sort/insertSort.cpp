#include<iostream>
using namespace std;
void insertSort(int arr[],int n)
{
	int i,j,tmp;
	for(i=1;i<n;i++)
	{
		for(j=i;j>0;j--)
		{
			if(arr[j]<arr[j-1])
			{
				tmp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=tmp;
			}
			else{
				break;
			}
		}
	}
}

void insertSort_1(int arr[],int n)
{
	int i,j,tmp,elem;

	for(i=1;i<n;i++)
	{
		elem=arr[i];
		for(j=i;j>0;j--)
		{
			if(elem<arr[j-1])
			{
				arr[j]=arr[j-1];
			}
			else
			{
				break;
			}
		}
	arr[j]=elem;
	}
}

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int n,a[1000];
	printf("How many numbers do you want to sort:");
	scanf("%d",&n);
	printf("Please enter the numbers you want to sort:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertSort_1(a,n);
	printArray(a,n);
	return 0;
}
		


