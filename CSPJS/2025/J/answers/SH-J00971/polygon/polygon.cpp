#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,flag,a[5010],sum[5010][5010],num,ans[5010],cnt;
void dfs(int now,int idx,int maxn,int x)
{
	if(now>=3&&x>maxn*2) cnt++;
	if(now==3) return;
	if(idx==now+1) dfs(now-1,now,a[now-1],x-a[now]);
	if(x<=maxn*2) return;
	if(idx==now+1) for(int i=idx-2;i>=1;i--) dfs(now-1,i,maxn,x-a[i]);
	else for(int i=idx-1;i>=1;i--) dfs(now-1,i,maxn,x-a[i]);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=2;i<=5000;i++)
	{
		flag=1;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		a[i]=flag;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]) sum[i][i]=1;
		else
		{
			num=i;
			for(int j=2;j*j<=i;j++)
			{
				while(num%j==0)
				{
					sum[i][j]++;
					num/=j;
				}
			}
			if(num!=1) sum[i][num]++;
		}
	}
	flag=1,num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num+=a[i];
		if(a[i]>1) flag=0;
	}
	sort(a+1,a+n+1);
	if(flag)
	{
		num=1;
		for(int i=2;i<=n;i++) ans[i]+=sum[n][i]+sum[n-1][i]+sum[n-2][i];
		ans[2]--,ans[3]--;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=ans[i];j++)
				num=num*i%998244353;
		cnt+=num;
		for(int i=4;i<=n;i++)
		{
			num=1;
			for(int j=2;j<=n;j++) ans[j]+=sum[n-i+1][j]-sum[i][j];
			for(int i=2;i<=n;i++)
				for(int j=1;j<=ans[i];j++)
					num=num*i%998244353;
			cnt=(cnt+num)%998244353;
		}
		cout<<cnt;
	}
	else
	{
		dfs(n,n+1,a[n],num);
		cout<<cnt;
	}
}
