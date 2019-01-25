#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int ElementType;
struct StackType {
	int top;
	int max;
	ElementType* Stack;
};
typedef StackType * Stack;
int IsFull(Stack S);
int IsEmpty(Stack S);
void Push(Stack S, ElementType item);
ElementType Pop(Stack S);
int main() {
	ElementType max1, max2, item1;
	char q;
	scanf("%d", &max1);
	scanf("%d", &max2);
	getchar();
	if (max1 < max2) {
		int temp = max1;
		max1 = max2;
		max2 = temp;
	}
	struct StackType s1, s2;
	s1.Stack = (ElementType*)calloc(max1, sizeof(ElementType));
	s2.Stack = (ElementType*)calloc(max2, sizeof(ElementType));
	s1.max = max1;
	s2.max = max2;
	s1.top = -1;
	s2.top = -1;
	scanf("%c", &q);
	while (q != 'T') 
	{
		if (q == 'A') 
		{
			scanf("%d", &item1);
			if (IsFull(&s2)&&!IsEmpty(&s1))
			{
				printf("ERROR:Full\n");
			}
			else if (IsFull(&s2) && IsEmpty(&s1))
			{
				while (!IsEmpty(&s2))
				{
					Push(&s1, Pop(&s2));
				}	
				Push(&s2, item1);
			}
			else
			{
				Push(&s2, item1);
			}
		}
		if (q == 'D')
		{
			if (IsEmpty(&s1) && IsEmpty(&s2))
			{
				printf("ERROR:Empty\n");
			}
			
			if (IsEmpty(&s1) && !IsEmpty(&s2))
			{
				while (!IsEmpty(&s2))
				{
					int temp=Pop(&s2);
					Push(&s1, temp);
				}
				printf("%d\n", Pop(&s1));
			}
			else if (!IsEmpty(&s1))
			{
				printf("%d\n", Pop(&s1));
			}
			
		}
		getchar();
		scanf("%c", &q);
	}
	free(s1.Stack);
	free(s2.Stack);
	return 0;
}
int IsFull(Stack S)
{
	if (S->top == S->max - 1)
		return 1;
	else
		return 0;
}
int IsEmpty(Stack S)
{
	if (S->top == -1)
		return 1;
	else
		return 0;
}
void Push(Stack S, int item)
{
	if (!IsFull(S))
	{
		S->top++;
		S->Stack[S->top] = item;
	}
}
ElementType Pop(Stack S)
{
	int item1;
	item1 = S->Stack[S->top--];
	return item1;
}
