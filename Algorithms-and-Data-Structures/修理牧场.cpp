#include<iostream>
#include<stdlib.h> 
using namespace std;
//void insertSort(int a[],int n);
//void sort(int *num,int n);

/*void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] <= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                s[i++] = s[j];
 
            while(i < j && s[i] > x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
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
	int temp;  //����һ����ʱ���������ڽ�������ʱ�洢 
    for(i=1;i<len;i++){  //��Ϊ����Ҫ�Ըô������е�ÿһ��Ԫ�ض���ǰ������ź�������н��в��룬�������ǻ�����н��б��� 
       for(j=0;j<i;j++){  //�ڶ���ѭ����Ҫ���ڶ����ź�������н���ɨ�裬��Ҫ������������ݽ�����һ�Ƚϣ�Ȼ��������뵽���� 
            if(arr[j]<arr[i]){//��ǰ��������ź����Ԫ�غʹ�����Ԫ�ؽ��д�С�Ƚϣ�Ȼ��ֱ���ҵ�һ��Ԫ�رȱ�����Ԫ�ش��򽻻�λ�� 
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
