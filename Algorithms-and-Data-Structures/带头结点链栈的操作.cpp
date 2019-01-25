#include <malloc.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
		struct LNode * next;
}LNode,*LinkList;

//Status InitList(LinkList L);
/*Status List(LinkList L);
Status ListInsert(LinkList L,int i,ElemType e);*/
LNode* InitLink();
Status Push(LinkList L, ElemType e);
Status Pop(LinkList L, ElemType *e);
int main()
{

  LinkList L;
  L=InitLink();
  int x;
  //InitList(L);
  Push(L,1);Push(L,2);Push(L,3);
  printf("%d",L->data);
//  List(L);
  Pop(L,&x);
  printf(" %d\n",x);
 // List(L);
  return 0;
}
LNode* InitLink(){
	LinkList temp;
	temp=(LinkList)malloc(sizeof(struct LNode));
	if(!temp){
		return NULL;
	}
	temp->next=NULL;
	return temp;
}
Status Push(LinkList L, ElemType e)
{
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return OK;
}
Status Pop(LinkList L, ElemType *e)
{
    LinkList p;
    p = L->next;
    *e = p->data;
    free(L);
    L=p->next;
    return OK;
}
