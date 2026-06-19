#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int maxa=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		s[i]=(a[i]^s[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==k&&(s[n]^s[i])==k)
		{
			maxa=2;
		}
	}
	cout<<maxa<<endl;
	return 0;
}
