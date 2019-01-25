#include <iostream>
#include <string>
//#include<assert.h>
//#include "stdlib.h"
//#include "stdio.h"
using namespace std;
int KMP(string &T, string &P);
int main()
{
	string a, b;
	int c;
	int num[20];
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		cin >> a;
		cin >> b;
		if (KMP(a, b) == -1)
			num[i] = -1;
		else
			num[i]=KMP(a,b);
	}
	for (int i = 0; i < c; i++)
	{
		if (num[i] == -1)
			cout << "not find!"<<endl;
		else
			cout << num[i] << endl;
	}
}
int KMP(string &T, string &P)
{
	int i = 0;
	int j = 0;
	int pLen = P.length();
	int tLen = T.length();
	if (tLen < pLen)
		return (-1);
	while (i < pLen&&j < tLen)
	{
		if (T[j] == P[i])
		{
			i++;
			j++;
		}
		else {
			j = j - i + 1;
			i = 0;
		}
	}
	if (i >= pLen)
		return (j - pLen );
	else
		return (-1);
}
