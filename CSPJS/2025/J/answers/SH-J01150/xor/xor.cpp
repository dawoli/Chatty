# include <bits/stdc++.h>//ÕâÌâÊ«ÈË£¿£¿£¿ 
using namespace std;
int n,k,res=0;
int a[500005]={0};
int dp[500005]={0};
int yh(int a,int b)
{
	int ax[25]={0},bx[25]={0};
	int cnt1=-1,cnt2=-1,ans=0;
	while(a>0)
	{
		cnt1++;
		ax[cnt1]=a%2;
		a/=2;
	}
	while(b>0)
	{
		cnt2++;
		bx[cnt2]=b%2;
		b/=2;
	}
	for(int i=max(cnt1,cnt2);i>=0;i--)
	{
		if(ax[i]==bx[i])
		{
			ans*=2;
		}
		else
		{
			ans=ans*2+1;
		}
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=a[i];
		if(a[i]==k)
		{
			dp[i]=max(dp[i],dp[i-1]+1);
		}
		for(int j=i-1;j>=1;j--)
		{
			cnt=yh(cnt,a[j]);
			if(cnt==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		res=max(res,dp[i]);
	}
	cout<<res;
	return 0;
}
