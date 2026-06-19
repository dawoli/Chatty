#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int r[MAXN], cnt[MAXN], n, p, ans;
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r,r+n+1);
	p=1;
	for(int i=1;i<=n;i++)
	{
		if(r[i]!=r[p])
		{
			r[++p]=r[i];
		}
		cnt[p]++;
	}
	for(int i=2;i<=p;i++)
	{
		ans-=min(cnt[i], cnt[i-1]);
		if(cnt[i]<cnt[i-1])
		{
			cnt[i]+=cnt[i-1]-cnt[i];
		}
	}
	cout<<ans;
}
