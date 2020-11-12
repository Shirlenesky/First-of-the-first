#include<algorithm>
#include<iostream>
#include <assert.h>
using namespace std;
template<typename T>
class myvector
{
	public:
		myvector():array(0),thesize(0),thecapacity(0){}
		myvector(const T& t ,unsigned int n):array(0),thesize(0),thecapacity(0)
		{
			while(n--)
			{
				push_back(t);
			}
		}
		myvector(const myvector<T>& other):array(0),thesize(0),thecapacity(0)
		{
			*this = other;
		}
		myvector<T>& operator =(myvector<T>& other)
		{
        if(this == &other)
            return *this;
        clear();
        thesize = other.size();
        thecapacity = other.capacity();
        array = new T[thecapacity];
        for(unsigned int i = 0 ;i<thesize;++i)
        {
            array[i] = other[i];
        }
        return *this;
    	}
		
		~myvector()
		{
			clear();
		}
		T&operator[](unsigned int pos)
		{
			if(pos < thesize)	return array[pos];
		}
		unsigned int size()
		{
			return thesize;
		}
		unsigned int capacity()
		{
			return thecapacity;
		}
		bool empty()
		{
			return thesize == 0;
		}
		void clear()
		{
			deallocator(array);
			array = 0;
			thesize = 0;
			thecapacity = 0;
		}
		
		void push_back(const T&t)
		{
			insert_after(thesize-1,t);
		}
		void push_front(const T&t)
		{
			insert_before(0,t);
		}
		void insert_after(int pos,const T&t)
		{
			insert_before(pos+1,t);
		}
		void insert_before(int pos,const T&t)
		{
			if(thesize == thecapacity)
			{
				T* oldarray = array;
				thecapacity += 64;
				array = allocator(thecapacity);
				for(unsigned int i=0;i<thesize;i++)
				{
					array[i] = oldarray[i];
				}
				deallocator(oldarray);
			}
			
			for(int i=(int)thesize++;i>pos;--i)
			{
				array[i]=array[i-1];
			}
			array[pos] = t;
		}
		void erase(int pos)
		{
			if(pos<thesize)
			{
				thesize--;
				for(unsigned int i=pos;i<thesize;i++)
				{
					array[i]=array[i+1];
				}
			}
			
		}
	private:
		T* allocator(unsigned int size)
		{
			return new T[size];
		}
		void deallocator(T* arr)
		{
			if(arr) delete[] arr;
		}
		T* array;
		unsigned int thesize;
		unsigned int thecapacity;
		
		
		
		
};
void printvec(myvector<int> &vector1)
{
	cout<<"vector包含的内容：";
	for(unsigned int i=0;i<vector1.size();i++)
	{
		cout<<vector1[i]<<" ";
	}
	cout<<endl;
	cout<<"vector的容量是" <<vector1.capacity()<<"vector的大小"<<vector1.size()<<endl; 
}

int main()
{
	myvector<int> myvector1;
	myvector<int> myvector2(0,10);
	myvector2.push_front(1);
	myvector2.erase(11);
	printvec(myvector2);
	myvector1.push_back(2);
	myvector1.push_front(1);
	printvec(myvector1);
	
	myvector2 = myvector1;
	myvector2.insert_before(0,0);
	myvector2.insert_before(1,-1);
	printvec(myvector2);
	return 0;
	
}

