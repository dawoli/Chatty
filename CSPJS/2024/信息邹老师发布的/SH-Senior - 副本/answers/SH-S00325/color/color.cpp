#include <bits/stdc++.h>
using namespace std;

int t,n;
const int N=2e5+7;
int a[N],sum,ans;
bool c[N],flag[N];
stack <int> r,b;
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
void dfs(int depth)
{
	if(depth==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	c[depth]=0;
	if(!r.empty()&&r.top()==a[depth])
		sum+=a[depth],flag[depth]=true;
	r.push(a[depth]);
	dfs(depth+1);
	sum-=(flag[depth])?a[depth]:0;
	flag[depth]=false;
	r.pop();
	c[depth]=1;
	if(!b.empty()&&b.top()==a[depth])
		sum+=a[depth],flag[depth]=true;
	b.push(a[depth]);
	dfs(depth+1);
	sum-=(flag[depth])?a[depth]:0;
	flag[depth]=false;
	b.pop();
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		ans=0;
		memset(flag,false,sizeof(flag));
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
100
17 18 18 19 17 19 20 20 18 19 18 19 18 19 19 19 18 17 19 17 40 40 40 37 40 39 39 39 38 39 38 40 37 40 38 40 38 39 39 40 59 60 58 60 59 58 59 58 60 57 58 60 57 60 57 60 58 60 57 60 80 80 79 80 78 77 80 79 79 80 79 79 79 77 80 77 77 80 80 78 100 100 98 97 97 99 98 99 100 99 100 98 98 99 98 98 100 100 97 98

*/
