#include <iostream>
#include <malloc.h>
#define maxsize 100
typedef char ElemType;
typedef struct
{
	ElemType data[maxsize];
	int top;
}Sqstack;
template <class T>
class mystack
{
	public:
		void initstack(Sqstack *&s);
		void destroystack(Sqstack *&s);
		bool emptystack(Sqstack *s);
		bool push_stack(Sqstack *&s,ElemType e);
		bool pop_stack(Sqstack *&s,ElemType &e);
		bool gettop(Sqstack *s,ElemType e);
	
		
		
};
template<class T>
void mystack<T>::initstack(Sqstack *&s)
{
	s=(Sqstack*)malloc(sizeof(Sqstack));
	s->top=-1;
}

template<class T>
void mystack<T>::destroystack(Sqstack *&s)
{
	free(s);
}

template<class T>
bool mystack<T>::emptystack(Sqstack *s)
{
	return (s->top==-1);
}

template<class T>
bool mystack<T>:: push_stack(Sqstack *&s,ElemType e)
{
	if(s->top==maxsize-1)
	{
		return false;
	}
	s->top++;
	s->data[s->top]=e;
	return true;
}

template<class T>
bool mystack<T>::pop_stack(Sqstack *&s,ElemType &e)
{
	if(s->top==-1)
	{
		return false;
	}
	e=s->data[s->top];
	s->top--;
	return 1;
	
}

template<class T>
bool mystack<T>::gettop(Sqstack *s,ElemType e)
{
	if(s->top==-1)
	{
		return false;
	}
	e=s->data[s->top];
	return 1;
	
}
using namespace std;
int main()
{
	ElemType e;
	Sqstack *s;
	mystack<char>a;
	cout<<"˳��ջs�Ļ����������£�"<<endl;
	cout<<"1 ��ʼ��ջ"<<endl;
	a.initstack(s);
	printf("2 ջΪ %s\n",(a.emptystack(s)? "��":"�ǿ�"));
	cout<<"3  ���ν�ջ��˳��Ϊa b c d e"<<endl;
	a.push_stack(s,'a');
	a.push_stack(s,'b');
	a.push_stack(s,'c');
	a.push_stack(s,'d');
	a.push_stack(s,'e');
	printf("4 ջΪ %s\n",(a.emptystack(s)? "��":"�ǿ�"));
	cout<<"��ջ˳��Ϊ:"<<endl;
	while(!a.emptystack(s)) 
	{
		a.pop_stack(s,e);
		cout<<e<<" ";
	}
	cout<<endl;
	printf("6 ջΪ %s\n",(a.emptystack(s)? "��":"�ǿ�"));
	cout<<"7 �ͷ�ջ"<<endl;
	a.destroystack(s);
	return 0;
}
//����д���� 
