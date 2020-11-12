#include <malloc.h> 
#include <iostream>
#define maxsize 50
using namespace std;
typedef char elemtype;
typedef struct 
{
	elemtype data[maxsize];
	int len;
}sqlist;

template <class T>
class mylist
{
	public:
		void createlist(sqlist *&L, elemtype a[], int n);
		void initlist(sqlist *&L);
		void destroylist(sqlist *&L);
		bool emptylist(sqlist *L);
		int listlenght(sqlist *L);
		void displist(sqlist *L);
		bool getelem(sqlist *L,int i, elemtype &e);
		int locateelem(sqlist *L,elemtype e);
		bool listinsert(sqlist *&L,int i,elemtype e);
		bool listdelete(sqlist *&L,int i,elemtype &e);
		
};

template <class T>
void mylist<T>::createlist(sqlist *&L, elemtype a[], int n)
{
	L=(sqlist *)malloc(sizeof(sqlist));
	for(int i=0;i<n;i++)
	{
		L->data[i]=a[i];
	}
	L->len=n;
}

template<class T>
void mylist<T>::initlist(sqlist *&L)
{
	L=(sqlist *)malloc(sizeof(sqlist));
	L->len=0;
}

template<class T>
void mylist<T>::destroylist(sqlist *&L)
{
	free(L);
}

template<class T>
bool mylist<T>::emptylist(sqlist *L)
{
	return (L->len == 0);
}

template<class T>
int mylist<T>::listlenght(sqlist *L)
{
	return (L->len);
}

template<class T>
void mylist<T>::displist(sqlist *L)
{
	for(int i=0;i < L->len;i++)
	{
		cout<<L->data[i]<<" ";
	}
	cout<<endl;
}

template<class T>
bool mylist<T>::getelem(sqlist *L,int i,elemtype &e)
{
	if(i<1 || i>L->len)	return false;
	e=L->data[i-1];
	return true;
}

template<class T>
int mylist<T>::locateelem(sqlist *L,elemtype e)
{
	int i=0;
	while(i<L->len || L->data[i]!=e)
	{
		i++;
	}
	if(i>=L->len)
	{
		return false;	
	}
	else
	{
		return i+1;
	}
}
template<class T>
bool mylist<T>::listinsert(sqlist *&L,int i,elemtype e)
{
	int j;
	if(i<1 || i>L->len+1 || L->len==maxsize)
	{
		return false;
	}
	i--;
	for(j=L->len;j>i;j--)
	{
		L->data[j]=L->data[j-1];
	}
	L->data[i]=e;
	L->len++;
	return true;
}

template<class T>
bool mylist<T>::listdelete(sqlist *&L,int i,elemtype &e)
{
	int j;
	if(i<1 || i>L->len)	return false;
	i--;
	e=L->data[i];
	for(j=i;j<L->len-1;j++)
	{
		L->data[j]=L->data[j+1];
	}
	L->len--;
	return true;
}

int main() 
{
	sqlist *L;
	elemtype e;
	mylist<int> a;
	cout<<"1 初始化list"<<endl;
	a.initlist(L);
	cout<<"2 依次放入 a b c d e "<<endl;
	a.listinsert(L,1,'a');
	a.listinsert(L,2,'b');
	a.listinsert(L,3,'c');
	a.listinsert(L,4,'d');
	a.listinsert(L,5,'e');
	cout<<"3 输出list"<<endl;
	a.displist(L);
	cout<<endl;
	cout<<"4 输出list的长度"<<endl;
	cout<<a.listlenght(L);
	cout<<endl;
	printf("5 list为 %s\n", a.emptylist(L)?"空":"非空");
	a.getelem(L,3,e);
	cout<<"6 输出list的第三个元素"<<endl;
	cout<<"7 输出a的位置"<<endl;
	a.locateelem(L,'a');
	cout<<endl;
	cout<<"8 在第四个元素上插入元素f"<<endl;
	a.listinsert(L,4,'f');
	cout<<"9 输出现在的list"<<endl;
	a.displist(L);
	cout<<endl;
	cout<<"10 删除第三个元素"<<endl;
	a.listdelete(L,3,e);
	cout<<"11 输出现在的list"<<endl;
	a.displist(L);
	cout<<endl;
	cout<<"12 释放list"<<endl;
	a.destroylist(L);
	
	return 0;
}
