#include<bits/stdc++.h>
using namespace std;
const int MAXN=500,MOD=998244353;
int n,m,c[MAXN+5];
long long ans,a[MAXN+5];
bool vis[MAXN+5];
string s;
void dfs(int pos,int lose)
{
	if (pos-lose-1>=m)
	{
		ans=(ans+a[n-pos+1])%MOD;
		return;
	}
	if (pos==n+1)
	{
		return;
	}
	if (n-lose<m)
	{
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			dfs(pos+1,lose+(s[pos]=='0'||lose>=c[i]));
			vis[i]=0;
		}
	}
	return;
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>m>>s;
	s=' '+s;
	a[0]=1;
	for (int i=1;i<=n;i++)
	{
		a[i]=(a[i-1]*i)%MOD;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	dfs(1,0);
	cout<<ans;
	return 0;
}
