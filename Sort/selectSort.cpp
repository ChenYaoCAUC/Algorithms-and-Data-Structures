#include<iostream>
using namespace std;
void selectSort(int arr[],int n)
{
	int i,j,minValue,tmp;
	for(i=0;i<n-1;i++){
		minValue=i;
		for(j=i+1;j<n;j++){
			if(arr[minValue]>arr[j]){
				minValue=j;
			}
		}
		if(minValue!=i)
		{
			tmp = arr[i];
			arr[i]=arr[minValue];
			arr[minValue]=tmp;
		}
	}
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
	int n,arr[1000];
	printf("How many numbers do you want to sort:");
	scanf("%d",&n);
	printf("Plaese enter the number you want to sort:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selectSort(arr,n);
	printArray(arr,n);
	return 0;
}
