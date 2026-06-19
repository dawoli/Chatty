#include<bits/stdc++.h>
using namespace std;
//不开long long 见祖宗，空间不开够见祖宗 
long long n,m,ans=1;
char s[555];
long long f[505][505],g,c[505],cc[505];
//f[i][j][k] 前i个过了j个入,过关人选。k=0不过， k=1过 
const long long mod = 998244353;
bool u[505];
long long x[505];
void dfs(long long dep,long long ps)
{
	if(dep==n)
	{
		//cout<<ps<<endl;
		if(ps>=m) ans++;
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(u[i]==0)
		{
			u[i] = 1;
			if(dep-ps<cc[i]&&s[dep]=='1') dfs(dep+1,ps+1);
			else dfs(dep+1,ps);
			u[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++)
	{
		cin>>g;
		c[g] ++;
		cc[i] = g;
	}
	for(int i = n;i>=0;i--) c[i] += c[i+1];
	bool ak = 1;
	for(int i = 0;i<strlen(s);i++)
	{
		if(s[i]=='0')
		{
			//cout<<i<<endl;
			ak = 0;
		}
	}
	if(m==n)
	{
		if(c[1]==n&&ak)
		{
			for(int i = 1;i<=n;i++)
			{
				ans = (ans*i)%mod;
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
		return 0;
	}
	ans = 0;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
