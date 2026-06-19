#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=1e6+5;
int T,n,a[maxn],c[maxm],d[maxn],i,j;
long long b[maxn],ans;
void dfs(int x,int col,int pre1,int pre2,long long cnt)
{
	if (b[x]+cnt<=ans) return;
	if (x>n) 
	{
		ans=max(ans,cnt);
		return;
	}
	if (col==1)
	{
		if (a[pre1]==a[x]) cnt+=a[x];
		dfs(x+1,1,x,pre2,cnt);
		dfs(x+1,2,x,pre2,cnt);
	}
	else
	{
		if (a[pre2]==a[x]) cnt+=a[x];
		dfs(x+1,2,pre1,x,cnt);
		dfs(x+1,1,pre1,x,cnt);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout); 
	cin>>T;
	while (T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));ans=0;memset(c,0,sizeof(c));memset(d,0,sizeof(d));
		for (i=1;i<=n;++i) scanf("%d",&a[i]),d[i]=c[a[i]],c[a[i]]++;
		for (i=n;i>=1;--i)//后缀和预处理 
		{
		 	if (d[i]) b[i]=b[i+1]+a[i];
		 	else b[i]=b[i+1];
		}
		dfs(1,1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
