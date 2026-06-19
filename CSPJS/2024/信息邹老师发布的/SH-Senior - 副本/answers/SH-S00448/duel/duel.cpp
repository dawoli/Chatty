#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int f[105]={0};
	int a[105]={0};
	int maxn=-1;
	int minn=1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	int h=n;
	int l=f[minn];
	for(int i=minn+1;i<=maxn;i++)
	{
		if(f[i]==0)
		{
			continue;
		}
		if(f[i]>=l)
		{
			l+=f[i];
			h-=(l-f[i]);
			l-=(l-f[i]);
		}
		else if(f[i]<l)
		{
			l+=f[i];
			h-=f[i];
			l-=f[i];
		}
	}
	cout<<l;
	return 0;
}
