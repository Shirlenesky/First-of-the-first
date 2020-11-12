#include<iostream>
using namespace std;
template class <T>;
class myvector
{
	public:
	{
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_tpye;
	}
	private:
	{
		iterator start;
		iterator finish;
		iterator end_of_storage;
		std::allocator<T> alloc;
	}	
	public:
	{
		iterator begin(){return start;}
		const iterator begin() const {return start;}
		iterator end(){return finish;}
		const iterator end() const {return finish;}
		
		size_type size() const {return (size_type)( end() - begin() );}
		size_type capacity() const {return (size_type)( end_of_storage - begin() );}
		
		bool empty(){ return begin() == end();}
		
		myvector(): start(0),finish(0),end_of_storage(0){		}
		myvector(size_type n, const T& value){start=alloc.		}
		myvector(iterator first,iterator last);
		
	}
		
	
	
}
int main()
{
	
	
	
	
}
