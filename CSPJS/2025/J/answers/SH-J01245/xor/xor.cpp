#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
bool flag=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+5]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=1)
		{
			flag=0;
			break;
		}
	}
	if(flag || k==0)
	{
		cout<<n;
		return 0;
	}
	int nows=a[0];
	for(int i=1;i<n-1;i++)
	{
		if(a[i]!=nows)
		{
			ans++;
			nows=a[i+1];
			continue;
		}
		nows=nows^a[i];
	}
	cout<<ans;
	return 0;
}
