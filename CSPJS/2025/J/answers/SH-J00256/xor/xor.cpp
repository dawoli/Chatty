#include<bits/stdc++.h>
using namespace std;
int a[300000];
bool b[300000];
int main()
{
	int n,k,one=0,zero=0,cnt1=0,cnt0=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			one++;
		else
			zero++;
		if(a[i-1]==0&&a[i]==0&&!b[i-1])
		{
			b[i]=1;
			cnt1++;
		}
		if(a[i-1]==1&&a[i]==1&&b[i-1])
		{
			cnt0++;
			b[i]=1;
		}
	}
	if(one==n)
		cout<<n/2;
	else
	{
		if(k==1)
			cout<<cnt0+one;
		else
			cout<<zero+cnt1;
	}
	return 0;
}
