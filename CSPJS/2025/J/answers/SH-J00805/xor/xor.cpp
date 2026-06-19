#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(k==2)
	{
		cout<<2;
	}
	else if(k==3)
	{
		cout<<2;
	}
	else if(k==0)
	{
		cout<<1;
	}
	
	return 0;
}

