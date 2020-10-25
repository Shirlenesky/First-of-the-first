#include <stdio.h>
using namespace std;
void *mymemcpy(void*dest, const void *src, size_t n)
{
	
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	while(n--)
	{
		*pdest++ = *psrc++;
	}
	return pdest;
}

int main()
{
	char c1[]="who lives in the pineapple under the sea?";
	char c2[101];
	mymemcpy(c2,c1,5);
	printf("%s",c2);
	
	
	return 0;
}
