#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

void swap(int *a,int *b)
{
	int tmp;

	tmp=*a;
	*a=*b;
	return;
}

static int partition(int arr[],int l,int r)
{
 	int i,j;
	i=l+1;
	j=l;

	while(i<=r)
	{
		if(arr[i]>arr[l])
		{
			i++;
		}
		else{
			swap(&arr[j+1],&arr[i]);
			i++;
			j++;
		}
	}
	swap(&arr[l],&arr[j]);
	return j;
}

static void _quickSort(int arr[],int l,int r)
{
	int key;
	if(l>=r)
	{
	return;
	}
	key=partition(arr,l,r);
	_quickSort(arr,l,key-1);
	_quickSort(arr,key+1,r);
}
void quickSort(int arr[],int n)
{
	_quickSort(arr,0,n-1);
}
int main()
{
	int arr[10]={1,2,3,5,4,2,7,6,4,7};

	printArray(arr,10);
	quickSort(arr,10);
	printArray(arr,10);
	return 0;
}

