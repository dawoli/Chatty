#include<bits/stdc++.h>
using namespace std;
const int maxx=2e5+5;
const int moremax=1e6+5;
long long dp[maxx][2];
long long ans;
int num[maxx];//记录缩点后的数字 
int lct[moremax];//读入时用于寻找前驱 
int pre[maxx];//记录前驱 
int T,n;
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
int init()
{
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	memset(lct,0,sizeof(lct));
	ans=0;n=0;
	n=read();
	int last=0,tmp=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		tmp=read();
		if(tmp==last) ans+=tmp;
		else
		{
			last=tmp;
			num[++cnt]=tmp;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		pre[i]=lct[num[i]];
		lct[num[i]]=i;
	}
	return cnt;
}
void solve(int cnt)
{
	for(int i=1;i<=cnt;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(pre[i]==0) dp[i][1]=dp[i][0];
		else
		dp[i][1]=max(dp[pre[i]+1][0]+num[i],dp[pre[i]+1][1]+num[i]);
	}
	ans+=max(dp[cnt][0],dp[cnt][1]);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++)
	{
		int cnt=init();
		solve(cnt);
		cout<<ans<<endl;
	}

	return 0;
} 
