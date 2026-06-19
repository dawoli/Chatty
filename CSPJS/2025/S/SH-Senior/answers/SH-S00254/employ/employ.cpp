#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pc putchar
int n,m;
string s;
int c[200010];
int p[200010];
int dp[350010][20][20];
const int mod=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	rep(i,1,n) cin>>c[i];
	if(m==n)
	{
		bool flg=0;
		rep(i,1,n)
		{
			if(s[i]=='0') flg=1;
		}
		rep(i,1,n) if(c[i]==0) flg=1;
		if(flg)
		{
			cout<<0<<'\n';
		}
		else
		{
			int ans=1;
			rep(i,1,n) ans*=i,ans%=mod;
			cout<<ans<<'\n';
		}
	}
	else if(m==1)
	{
		int ans=1;
		rep(i,1,n) ans*=i,ans%=mod;
		sort(c+1,c+n+1);
		rep(i,1,n) p[c[i]]++;
		int cnt=0,as=1,nw=0;
		int ct=0;
		rep(i,1,n)
		{
			cnt+=p[i-1];
			if(s[i]=='1')
			{
				++nw;
				if(cnt<nw)
				{
					as=0;
					break;
				}
				else
				{
					as*=(cnt-nw+1);as%=mod;
				}
			}
			else ct++;
		}
		rep(i,1,ct) as*=i,as%=mod; 
		ans-=as;
		cout<<(ans%mod+mod)%mod<<endl;
	}
	else
	{
		bool flg=0;
		rep(i,1,n) if(s[i]=='0') flg=1;
		if(!flg)
		{
			int ans=1;
			rep(i,1,n) ans*=i,ans%=mod;
			cout<<ans<<'\n';
		}
		else
		{
			if(n<=18)
			{
				//dp ijk
				//i yijingyongguoderen
				//j meitongguoderenshu
				dp[0][0][0]=1;
				rep(k,1,n)
				{
					rep(i,0,(1<<n)-1)
					{
						if(__builtin_popcount(i)!=(k-1)) continue;
						rep(l,1,n)
						{
							if(i&(1<<(l-1))) continue;
							rep(j,0,n)
							{
								if(c[l]>j&&s[k]=='1')dp[i+(1<<(l-1))][j][k]+=dp[i][j][k-1];
								else dp[i+(1<<(l-1))][j+1][k]+=dp[i][j][k-1];
							}
						}
					}
				}
				int ans=0;
				rep(i,0,n-m) ans+=dp[(1<<n)-1][i][n];
				cout<<ans<<endl;
			}
			else cout<<0<<endl;
		}
	}
} 
