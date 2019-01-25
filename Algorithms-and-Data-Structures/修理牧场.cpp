#include<iostream>
#include<stdlib.h> 
using namespace std;
//void insertSort(int a[],int n);
//void sort(int *num,int n);

/*void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] <= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];
 
            while(i < j && s[i] > x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}*/
int main()
{
	int *num;
	int sum,n,i,min1,min2,m1,m2,count;
	sum=0;
	cin>>n;
	num=new int[n];
	for(i=0;i<n;i++)
	{
		cin>>num[i];
	}
	if(n<2)
	{
		sum=num[0];
	}
	while(n>=2)
	{
		min1=num[0];
		min2=num[1];
		m1=0;
		m2=1;
		if(min1>min2)
		{
			int temp=min1;
			min1=min2;
			min2=temp;
			m1=1;
			m2=0;
		}
	//	cout<<min1<<" "<<min2<<" ";
		for(int i=2;i<n;i++)
		{
			if(min1>=num[i])
			{
				min2=min1;
				m2=m1;
				min1=num[i];
				m1=i;
				}
			else if(num[i]>=min1&&num[i]<=min2)
			{
				min2=num[i];
				m2=i;
				}
			else{
				break;
			}
	//		cout<<min1<<" "<<min2<<" "<<endl;
		}
//		cout<<min1<<" "<<min2<<" "<<endl;
		count=min1+min2;
		num[m2]=count;
		sum=sum+count;	
		n--;
		for(int j=m1;j<n;j++)
		{
			num[j]=num[j+1];
		}
	}
	cout<<sum;
}
/* void insertSort(int arr[],int len){
    int i;
    int j;
	int temp;  //定义一个临时变量，用于交换数据时存储 
    for(i=1;i<len;i++){  //因为我们要对该待排序列的每一个元素都和前面的已排好序的序列进行插入，所以我们会对序列进行遍历 
       for(j=0;j<i;j++){  //第二层循环主要用于对已排好序的序列进行扫描，和要插入进来的数据进行逐一比较，然后决定插入到哪里 
            if(arr[j]<arr[i]){//从前往后对已排好序的元素和待插入元素进行大小比较，然后直到找到一个元素比被插入元素大，则交换位置 
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
           }
       }
    }
 }
 */
 
/*
void sort(int num[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(num[j]<num[j+1])
			{
				int temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
 } 
 */
