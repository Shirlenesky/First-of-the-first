#include<stdio.h>
using namespace std;
char *strcpy(char *dest,const char *src)
{
	
	char *copy=dest;
	
	while(*src !='\0') 
	{
		*dest++ = *src++;
	}
	return copy;
}
int main()
{
	char c1[]="who lives in the pineapple under the sea?";
	char c2[101];
	strcpy(c2,c1);
	printf("%s",c2);
	
	return 0;
	
}
