/*二。用编辑器（记事本等）产生一个文本文件data.txt，其内容为若干实数，数据之间以空白字符分割。
编程从该文件中读入这些实数，求出这些实数的平均值，在程序中创建并产生一个文本文件result.dat，
内容为data.txt中的全体实数，每行5个数，最后一行是求出的平均值。*/
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
