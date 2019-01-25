#include<stdio.h>
#include<string.h>
int IsNum(char ch);
int Zhengfu(char ch);
int compare(char a,char b);
void F(char *a,int len);
int main(){
	char a[25];
	scanf("%s",a);
	int len=strlen(a);
	F(a,len);
	return 0;
}
int IsNum(char ch){
	return ch>='0'&&ch<='9'||ch=='.';
}
int Zhengfu(char ch){
	return ch=='+'||ch=='-';
}
int compare(char a,char b){ //判断是否出栈 
	if(b==')') return 1;
	if(a=='('||b=='(') return 0;
	if(b=='+'||b=='-') return 1;
	else if(b=='*'||b=='/'){
		if(a=='+'||a=='-') return 0;
		else if(a=='*'||a=='/') return 1;
	}
}
void F(char *a,int len){
	char stack[25];
	int top=0;
	int space = 0;//控制空格 
	for(int i=0;i<len;i++){
		if(IsNum(a[i])){
			if(space){
				printf(" ");
				space = 0;
			}
			printf("%c",a[i]);
		}
		else if(Zhengfu(a[i])&&(i?!IsNum(a[i-1])&&a[i-1]!=')':1)){//如果不是运算符，则直接输出 
			if(a[i]=='-'){ //只输出负号 
				if(space){
					printf(" ");
					space=0;
				}
				printf("%c",a[i]);
			}
		}
		else{
			if(top){
				if(a[i]==')')
				   while(top--){
				   	  if(stack[top]=='(') break;
				   	  printf(" %c",stack[top]);
				   }
				else{
					while(top){
						if(compare(stack[top-1],a[i])){
							printf(" %c",stack[--top]);
						}
						else break;
					}
					stack[top++]=a[i];
				}
			}
			else stack[top++]=a[i];
			for(int j=0;j<top;j++)
			 if(stack[j]!='('){
			 	space = 1;
			 	break;
			 }
		} 
	}
	while(top){
		printf(" %c",stack[--top]);
	}
}

