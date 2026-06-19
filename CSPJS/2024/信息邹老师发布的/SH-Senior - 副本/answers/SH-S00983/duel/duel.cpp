#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n,i,ans=0,a[M],mp[M],nxt[M],nxtN[M],nxtA[M],p=M,tmp=-1;
bool f[M];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int maxx=-1;
	for(i=1;i<=M;i++)
	{
		if(mp[i]>0)
		{
			maxx=max(maxx,i);
			if(tmp==-1)tmp=i,p=i;
			if(tmp!=-1)
			{
				nxt[tmp]=i;
				nxtN[tmp]=mp[a[i]];
				nxtA[tmp]=i;
			}
			tmp=i;
		}
	}
	while(1)
	{
		int t=min(nxtA[p],mp[p]);
		nxtA[p]-=t,mp[p]-=t;
		if(mp[p]==0)p=nxt[p];
		else if(nxtA[p]==0)
		{
			mp[nxt[p]]+=mp[p];
			mp[p]=0;
			p=nxt[p];
			nxtN[p]=mp[nxt[p]];
			nxtA[p]=nxt[p];
		}
		if(p==maxx)break;
	}
	for(i=1;i<=M;i++)
	{
		ans+=mp[i];
	}
	cout<<ans+1;
	return 0;
}
