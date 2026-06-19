#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,ans,p[15];
string f[100005];
int d[10] = {6,2,5,5,4,5,6,3,7,6};
void dfs(ll x,ll num)
{
	if(x >= n)
	{
		if(x == n) ans = min(ans,num);
		return;
	}
	for(ll i = 0;i <= 9;i++)
	{
		if(i == 0 && num == 0) continue;
		dfs(x + d[i],num * 10 + i);
	}
}
void solve1()
{
	ans = 1e9;
	p[1] = 1;
	for(ll i = 2;i <= 13;i++)
	{
		p[i] = p[i - 1] * 10;
	}
	dfs(0,0);
	if(ans != 1e9) cout<<ans<<endl;
	else cout<<-1<<endl;
}
bool bg(string x,string y)
{
	if(x.size() > y.size()) return 1;
	for(ll i = 0;i < x.size();i++)
	{
		if(x[i] > y[i]) return 1;
	}
	return 0;
}
void solve2()
{
	for(ll i = 1;i <= n;i++) f[i] = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	f[2] = "1";
	f[3] = "7";
	f[4] = "4";
	f[5] = "2";
	f[6] = "6";
	f[7] = "8";
	for(ll i = 8;i <= n;i++)
	{
		for(ll j = 2;j <= 7;j++)
		{
			string a = f[j];
			if(j == 6) a = "0";
			if(bg(f[i],f[i - j] + a)) f[i] = f[i - j] + a;
//			cout<<i<<" "<<j<<" "<<f[i]<<endl;
		}
//		cout<<i<<" "<<f[i]<<endl;
	}
	if(f[n] != "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999") cout<<f[n]<<endl;
	else cout<<-1<<endl;
//	cout<<30 / 7<<" "<<30 % 7<<endl;
//	cout<<f[n].size()<<endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n <= 30) solve1();
		else solve2();
	}
	return 0;
}
