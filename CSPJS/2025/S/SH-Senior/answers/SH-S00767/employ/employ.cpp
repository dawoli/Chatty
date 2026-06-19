#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int mod=998244353;
int n,m;
ll ans=0;
int sum=0;
string ss;
int c[502];
int dp[502][502];
int findf(int x)
{
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=((l+r)>>1);
		if(c[mid]>x)
		    r=mid;
		else
		    l=mid+1;
	}
	if(c[r]>x)
	    return r-1;
	return r;
}
inline int read()
{
	int rr=0,ww=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    ww=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		rr=rr*(1<<3)+rr*(1<<1)+ch-(1<<4)-(1<<5);
		ch=getchar();
	}
	return rr*ww;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>ss;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	sort(c+1,c+n+1);
	for(int i=0;i<n;i++)
	{
		if(ss[i]=='0')
		    sum++;
	}
	if(sum==0)
	{
		int ccnt=0;
		if(c[1]>0)
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=ans*i%mod;
			}
			cout<<ans;
			return 0;
		}
		for(int i=0;i<=n;i++)
		{
			if(i>=m)
			    dp[n][i]=1;
			else
			    dp[n][i]=0;
		}
		int fl1,fl2;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<=n;j++)
			{
				fl1=findf(j),fl2=n-findf(j);
				dp[i][j]=(dp[i+1][j]*fl1)%mod+(dp[i+1][j+1]*fl2)%mod;
			}
		}
		cout<<(dp[0][0]+mod)%mod;
	}
	cout<<"0"<<endl;
	return 0;
}
