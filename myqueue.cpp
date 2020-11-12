#include <iostream>
#include <malloc.h>
#define maxsize 100
using namespace std;
typedef char ElemType;
typedef struct
{
	ElemType data[maxsize] ;
	int front,rear;
}SqQueue;
template <class T>
class myqueue
{
	public:
		void initqueue(SqQueue *&q);
		void destroyqueue(SqQueue *&q);
		bool queueempty(SqQueue *&q);
		bool inqueue(SqQueue *&q,ElemType e);
		bool outqueue(SqQueue *&q,ElemType &e);		
};

template <class T>
void myqueue<T>::initqueue(SqQueue *&q)
{
	q=(SqQueue *)malloc(sizeof(SqQueue));
	q->front=q->rear;
}
template <class T>
void myqueue<T>::destroyqueue(SqQueue *&q)
{
	free(q);
}
template <class T>
bool myqueue<T>::queueempty(SqQueue *&q)
{
	return (q->front==q->rear);
}
template <class T>
bool myqueue<T>::inqueue(SqQueue *&q,ElemType e)
{
	if((q->rear+1)%maxsize==q->front) return false;
	q->rear=(q->rear+1)%maxsize;
	q->data[q->rear]=e;
}
template <class T>
bool myqueue<T>::outqueue(SqQueue *&q,ElemType &e)
{
	if(q->front==q->rear) return false;
	q->front=(q->front+1)%maxsize;
	e=q->data[q->front];
	return 1;
}
int main()
{
	ElemType e;
	SqQueue *q;
	myqueue<char> a;
	cout<<"环形队列q的基本运算如下："<<endl;
	cout<<"1 初始化队列"<<endl;
	a.initqueue(q);
	cout<<"2 进队 a b c"<<endl;
	if(!a.inqueue(q,'a')) cout<<"已满"<<endl;
	if(!a.inqueue(q,'b')) cout<<"已满"<<endl;
	if(!a.inqueue(q,'c')) cout<<"已满"<<endl;
	printf("3 栈为 %s\n",(a.queueempty(q)? "空":"非空"));
	if(a.outqueue(q,e)==0) cout<<"队空"<<endl;
	else cout<<"4 出队一个元素"<<e<<endl;
	cout<<"5 进队 d e f"<<endl;
	if(!a.inqueue(q,'d')) cout<<"已满"<<endl;
	if(!a.inqueue(q,'e')) cout<<"已满"<<endl;
	if(!a.inqueue(q,'f')) cout<<"已满"<<endl;
	cout<<"6 出队"<<endl;
	while(!a.queueempty(q))
	{
		a.outqueue(q,e);
		cout<<e<<" ";
	}
	cout<<endl;
	cout<<"7 释放队列"<<endl;
	a.destroyqueue(q);
	
	
	return 0;
}











