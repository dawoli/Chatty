#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N];
bool vis[N],hp[N];
int t;
inline int read()
{
	char ch=getchar();
	int res=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*f;
}
int find(int k)
{
	int tt=upper_bound(a+1,a+1+n,a[k])-a;
	int ttt=upper_bound(a+1,a+1+n,a[tt])-a-1;
	for(int j=tt;j<=ttt;j++)
	{
		if(vis[j]) return j;
	}
	if(ttt+1>n) return 0;
	return find(ttt+1);
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		vis[i]=hp[i]=true;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		t=(int)(find(i));
		if(t>n||t==0) break;
		vis[t]=false;
		hp[i]=false;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(hp[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
