#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1],add[n+1]={0},maxn=-9999999;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add[i]=max(add[i-1]+a[i],a[i]);
		maxn=max(add[i],maxn);
	}
	cout<<maxn;
	return 0;
}