#include<bits/stdc++.h>
#define ll long long
#define M 998244353
using namespace std;
int n,a[5005],maxn;
ll cnt;
bool vis[5005];
void dfs(ll len,ll k,int maxn,int last)//len:剩余几个元素；k:和为几 maxn：最大元素 last:上一次的值
{
	if(len==0)
	{
		if(k>2*maxn)
		{
			cnt++;
		}
		return;
	}
	for(int i=last;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(len-1,k+a[i],max(maxn,a[i]),i);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		for(int len=3;len<=n;len++)
		{
			ll cnt2=1;
			for(int i=1;i<=len;i++)
			{
				cnt2*=(n-i+1);
			}
			for(int i=1;i<=len;i++)
			{
				cnt2/=i;
			}
			cnt=(cnt+cnt2)%M;
		}
	}
	else
	{
		for(int len=3;len<=n;len++)
		{
			dfs(len,0,1,1);
			cnt%=M;
		}
	}
	cout<<cnt;
	return 0;
}
