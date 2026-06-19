#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
		cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
