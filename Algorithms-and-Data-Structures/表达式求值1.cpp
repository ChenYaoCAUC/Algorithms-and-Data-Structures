#include<stdio.h>
#include<string.h>
int IsNum(char ch);
int IsZhengFu(char ch);
int compare(char a,char b);
void Fuction(char *a,int len);
int main()
{
	char stack[20];
	scanf("%s",stack);
	int length=strlen(stack);
	Fuction(stack,length);
}
//返回数字 
int IsNum(char ch)
{
	if(ch>='0'&&ch<='9'||ch=='.')
	return 1;
	else
	return 0;
}
//返回正负号
int IsZhengFu(char ch)
{
	if(ch=='+'||ch=='-')
	{
		return 1;
	}
	else
	return 0;
}
//判断是否出栈 
int compare(char a,char b)
{
	if(b==')')
	return 1;
	if(a=='('||b=='(')
	return 0;
	if(a=='*'||a=='/')
	return 1;
	if(a=='+'||a=='-')
	{
		if(b=='+'||b=='-')
		{
			return 1;	
		}
		else if(b=='*'||b=='/')
		return 0;
	}
}
void Fuction(char *a,int len)
{
	char stack[20];
	//栈顶指针 
	int top=-1;
	//控制空格 
	int space=0;
	for(int i=0;i<len;i++)
	{
		if(IsNum(a[i]))
		{
			if(space)
			{
				printf(" ");
				space=0;
			}
			printf("%c",a[i]);
		}
		else if(IsZhengFu(a[i])&&!IsNum(a[i-1])&&a[i-1]!=')')
		{
			if(a[i]=='-')
			{
				if(space)
				{
					printf(" ");
					space=0;
				}
				printf("%c",a[i]);
			}
		}
		else
		{
			if(a[i]=='(')
			{
				stack[++top]=a[i];
				space=1;
			}
			else if(a[i]==')')
			{
				if(top!=-1)
				{
					while(stack[top]!='(')
					{
						printf(" %c",stack[top--]);
						space=1;
					}
				}
				
			}
			else
			{
				if(top!=-1)
				{
					while(top!=-1)
					if(compare(stack[top],a[i]))
					{
						printf(" %c",stack[top--]);
						space=1;
					}
					else 
					break;
				}
				else
				{
					stack[++top]=a[i];
				}
			}
			space=1;		
		}
		
		while(top!=-1)
		{
			printf(" %c",stack[top--]);
 		}
	
	}
}

