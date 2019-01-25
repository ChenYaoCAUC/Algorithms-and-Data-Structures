#include<iostream>
using namespace std;
void shellSort(int arr[],int n)
{
	int i,j,elem;
	int k=n/2;

	while(k>=1)
	{
		for(i=k;i<n;i++)
		{
			elem=arr[i];
			for(j=i;j>=k;j-=k)
			{
				if(elem<arr[j-k])
				{
					arr[j]=arr[j-k];
				}
				else
				{
					break;
				}
			}
			arr[j]=elem;
		}
		k=k/2;
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
	int n,array[1000];
	printf("How many numbers do you want to sort:");
	scanf("%d",&n);
	printf("Please enter the numbers you want to sort:");
	for(int i=0;i<n;i++){
		scanf("%d",&array[i]);
	}

	shellSort(array,n);
	printArray(array,n);
	return 0;
}
