#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],flag=1,vis=1,len,num,ans,dp[500010],sum[500010],l,r,cnt,x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(a[i]!=0&&a[i]!=1) vis=0;
		sum[i]=sum[i-1]^a[i];
	}
	if(flag) cout<<n/2;
	else if(vis)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans+=1+len/2,len=0;
				else len++;
			}
			cout<<ans+len/2;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1)
					ans++;
			cout<<ans;
		}
	}
	else
	{
		num=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=num;j<=i;j++)
			{
				if(1!=j&&i!=j)
				{
					cnt=1;
					x=max(sum[i],sum[j-1]);
					while(cnt<=x) cnt*=2;
					cnt=cnt-1-sum[i]&sum[j-1];
				}
				else if(j==1) cnt=sum[i];
				else cnt=a[i];
				if(!==k)
				{
					num=i+1;
					ans++;
					break;
				}
			}
		}
		cout<<ans;
	}
}
