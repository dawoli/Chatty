#include<bits/stdc++.h>
using namespace std;
int n,a[100010],last,ans,b[100010],c[100010],m;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(a[i]==a[i+1])
		{
			c[m]++;
		}
		else{
			b[++m]=a[i];
			c[m]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(last<c[i])
		{
			ans+=c[i]-last;
			last=c[i];
		}
	}
	cout<<ans;
	return 0;
}
