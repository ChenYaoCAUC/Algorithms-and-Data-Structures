/*�����ñ༭�������±��ȣ�����һ���ı��ļ�data.txt��������Ϊ����ʵ��������֮���Կհ��ַ��ָ
��̴Ӹ��ļ��ж�����Щʵ���������Щʵ����ƽ��ֵ���ڳ����д���������һ���ı��ļ�result.dat��
����Ϊdata.txt�е�ȫ��ʵ����ÿ��5���������һ���������ƽ��ֵ��*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	ofstream out,res;
	ifstream in;
	out.open("data.txt");
	int num=0;
	time_t current;
	time(&current);
	srand((unsigned int)current);
	for(int i=0;i<10000;i++){
		num=rand()%100;
		out<<num<<" ";
	}
	out.close();
	res.open("result.dat");
	in.open("data.txt");
	int sum=0,count=0,temp=0;
	while(in.eof()!=true){
		in>>temp;
		if(!in.eof())
		{ 
		    res<<temp<<" ";
		count++;
	
		if(count%5==0){
			res<<endl;
		}
		sum+=temp;
	}
		
	}
    double average=(double)sum/count;
    res<<endl;
    res<<average;
    res.close();
    in.close();
} 
