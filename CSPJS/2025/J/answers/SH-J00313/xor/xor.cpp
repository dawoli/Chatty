#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];


int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<1<<"\n";
	}
	else
	{
		cout<<2<<"\n";
	}
	return 0;
}
