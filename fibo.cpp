#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f1=1,f0=1,f2;
	int n;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		f2=f0+f1;
		f0=	f1;
		f1=f2;
	}
	cout<<f2;
	
	
	
}

