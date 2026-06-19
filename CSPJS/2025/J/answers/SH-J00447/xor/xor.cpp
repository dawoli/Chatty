#include<bits/stdc++.h>
using namespace std;
int n,m,k,p,t,sum,ans;
int a[500005];
int f[500005];
int ne[500005];
int h[1048585];
int l[500005];
int r[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];k^=a[i];}
	for(int i=n;i>=1;i--)
	{
		t++;
		f[t]=i;
		ne[t]=h[k];
		h[k]=t;
		k^=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		p=k^m;
		for(;h[p]!=0;)
		{
			if(f[h[p]]<i)h[p]=ne[h[p]];
			else break;
		}
		if(h[p]!=0)
		{
			sum++;
			l[sum]=i;
			r[sum]=f[h[p]];
		}
		k^=a[i];
	}
	k=n+1;
	for(int i=sum;i>=1;i--)
	{
		if(r[i]<k)
		{
			ans++;
			k=l[i];
		}
	}
	cout<<ans;
	return 0;
}
