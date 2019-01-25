#include<stdio.h>
#include<stdlib.h>
typedef struct Node* Link;
struct Node{
	int data1;
	int data2;
	struct Node* next;
};

Link InitLink();
void read(Link l);
void print(Link l);
void addition(Link l1,Link l2,Link l3);
//void multiplication(Link l1,Link l2,Link l3);

int main(){
	Link l1,l2,l3,l4;
	l1=InitLink();
	l2=InitLink();
	read(l1);
	read(l2);
	addition(l1,l2,l3);
//	multiplication(l1,l2,l4);
	print(l3);
//	print(l4);
	return 0;
}

Link InitLink(){
	Link l;
	l=(Link)malloc(sizeof(struct Node));
	if(!l)
	return NULL;
	l->next=NULL; 
	return l;
}
void read(Link l){
	int data1,data2;
	scanf("%d",&data1);
	scanf("%d",&data2);
	while(data2>0){
		Link temp;
		temp=(Link)malloc(sizeof(struct Node));
		if(!temp){
			return;
		}
		temp->data1=data1;
		temp->data2=data2;
		temp->next=NULL;
		l->next=temp;
		l=temp;
		scanf("%d",&data1);
		scanf("%d",&data2);
	}
}
void print(Link l){
	l=l->next;
	if(!l){
		printf("NULL");
		return;
	}
	while(l){
		if(l)
		{
		printf("%d ",l->data1);
		printf("%d ",l->data2);
		}
		else
		{
		printf("%d ",l->data1);
		printf("%d",l->data2);
		}
		l=l->next;
	}
	return;
}
void addition(Link l1,Link l2,Link l3)
{
	l1=l1->next;
	l2=l2->next;
	while(l1!=NULL&&l2!=NULL){
			if(l1->data2>l2->data2){
				l3->next=l1;
				l1=l1->next;
			}
			if(l2->data2>l1->data2){
				l3->next=l2;
				l2=l2->next;
			}
			if(l2->data2==l1->data2){
				l2->data1=l2->data1+l1->data1;
				l3->next=l2;
				l1=l1->next;
				l2=l2->next;
			}
			l3=l3->next;
		}
		if(l1==NULL&&l2==NULL)
		return;
		if(l1==NULL&&l2!=NULL){
			while(l2){
				l3->next=l2;
				l2=l2->next;
				l3=l3->next;
			}
		}
		if(l2==NULL&&l1!=NULL){
			while(l1){
				l3->next=l1;
				l1=l1->next;
				l3=l3->next;
			}
		}
		else
		return;
}

