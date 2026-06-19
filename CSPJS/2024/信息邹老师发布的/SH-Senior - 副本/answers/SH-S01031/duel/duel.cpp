#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int n,cnt,ans,lazy;
int mst[maxx];//记录怪兽r 
int q[maxx];//升序记录出现次数 
int pre[maxx];//记录前缀和 
int read()
{
	int x=0,f=1;char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void init()
{
	n=read();
	for(int i=1;i<=n;i++) mst[i]=read();
	sort(mst,mst+n+1);
	
	cnt=1;int last=mst[1];
	for(int i=1;i<=n;i++)
	{
		if(mst[i]==last) q[cnt]++;
		else
		{
			last=mst[i];
			pre[cnt]=pre[cnt-1]+q[cnt];
			q[++cnt]++;
		}
	}
	pre[cnt]=pre[cnt-1]+q[cnt];
}
void solve()
{
	ans=n;
	for(int i=2;i<=cnt;i++)
	{
		pre[i-1]-=lazy;
		if(pre[i-1]-q[i]<=0)
		{
			ans-=pre[i-1];
			lazy+=pre[i-1];
		}
		else
		{
			ans-=q[i];
			lazy+=q[i];
		}
	}
	return;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	init();
	solve();
	cout<<ans<<endl;
	return 0;
}
