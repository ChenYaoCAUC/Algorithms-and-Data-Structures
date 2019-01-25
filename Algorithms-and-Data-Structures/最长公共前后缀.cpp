#include <iostream>
#include <string>
#include "stdlib.h"
#include "stdio.h"
using namespace std;
int main()
{
	string String;
	cin >> String;
	int m, j, n, count = 0,flag=0;
	m = String.length();
	cout << 0;
	for (int i = 1; i < m; i++)
	{
		count = 0;
		flag = 0;
		j = i-1;
		n = i;
		//char *p = &String[i];
		//char *q = &String[i - 1];
		for (int k = 0; k < i; k++)
		{
			count = 0;
			n = i;
			while (String[n] != String[j] &&j>=0)
			{
				j--;
				if (j == -1)
				{
					flag = 1;
					break;
				}
			}
			if (j == -1)
				break;

			while(String[n] == String[j] && j>=0)
			{
				j--;
				n--;
				count++;
				if (j == -1)
				{
					break;
				}
			}
			if (j == -1)
			{
				flag = 0;
				break;
			}

		}

		if (flag == 0)
			cout << " " << count;
		else
			cout << " " << "0";
	}

}

