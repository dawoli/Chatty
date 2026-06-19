#include<bits/stdc++.h>
using namespace std;
int n,maxn,sum,ans,a[5010];
int A(int n,int m)
{
	int ans=1;
	for(int i=n;i>n-m;i--)
	{
		ans*=i;
	}
	return ans;
}
int C(int n,int m)
{
	return A(n,m)/A(m,m);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum<=2*maxn)
	{
		cout << 0;
		return 0;
	}
	if(n==3)
	{
		cout << 1;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		ans+=C(n,i);
	}
	cout << ans;
	return 0;
}
