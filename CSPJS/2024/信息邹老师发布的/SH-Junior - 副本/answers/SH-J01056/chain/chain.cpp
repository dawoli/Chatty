#include<bits/stdc++.h>
using namespace std;
const int a=1e5;
int n1[a];
int t,n,k,q;
bool flag1=1;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	cin>>n>>k>>q;
	for(int i=1;i<=t;i++)
	{
		cin>>n1[i];
	}
	while(flag1==1)
	{
		if(n1[a]==n)
		{
			cout<<1<<endl;
		}
		else 
		{
			cout<<0<<endl;
		}
		if(n1[a]==k)
		{
			cout<<1<<endl;
		}
		else 
		{
			cout<<0<<endl;
		}
		if(n1[a]==q)
		{
			cout<<1<<endl;
		}
		else 
		{
			cout<<0<<endl;
		}
		flag1=0;
	}
	return 0;
}
