#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll _1[520];
ll n,m,tot;
string s;
ll sum[520];
ll c[520];
bool f[520];
int g[520];
namespace A
{
	void dfs(ll i,ll cnt,ll tail)
	{
		//cout<<i<<' '<<cnt<<' '<<tail<<'\n';
		if(cnt==m)
		{
			tot=(_1[n-i+1]+tot)%mod;
//			for(int i=1;i<=n;i++)
//				if(f[i])
//					cout<<i<<' ';
//			cout<<n-cnt+1<<' '<<_1[n-cnt+1]<<'\n';
			return;
		}
		if(i>n)
			return;
		dfs(i+1,cnt,tail);
		tail++;
		while(tail<=n&&s[tail]!='1')
			tail++;
		if(c[i]<=sum[tail]||tail>n)
			return;
		//f[i]=1;
		dfs(i+1,cnt+1,tail);
		//f[i]=0;
	}
	void solve()
	{
		dfs(1,0,0);
		cout<<tot;
	}
}
namespace B
{
	bool check()
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(cnt>=c[g[i]]||s[i]=='0')
			{
				cnt++;
				if(cnt+m>n)
					return 0;
			}
		return 1;
	}
	void dfs(int i)
	{
		if(i>n)
		{
			tot+=check();
			if(clock()>=CLOCKS_PER_SEC*0.95)
			{
				cout<<tot;
				exit(0);
			 } 
			return;
		}
		for(int j=1;j<=n;j++)
			if(!f[j])
			{
				g[i]=j;
				f[j]=1;
				dfs(i+1);
				f[j]=0;
			}
	}
	void solve()
	{
		dfs(1);
		cout<<tot%mod;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	_1[0]=1;
	for(int i=1;i<=500;i++)
		_1[i]=_1[i-1]*i%mod;
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	B::solve();
	return 0;
}
