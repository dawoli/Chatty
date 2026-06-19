#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100010];
int vis[100010];
int ans;
void dfs(int x,int f,int p)
{
	if (x > n) 
		if (p >= m)
		{
			ans++;
			ans %= 998244353;
			return ;
		}
	for (int i = 1;i <= n;i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		if (p >= a[i] || s[x - 1] == '0') dfs(x + 1,f + 1,p);
		else dfs(x + 1,f,p + 1);
		vis[i] = 0; 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	cin >>n >>m;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >>a[i];
	 } 
	 dfs(1,0,0);
	 cout <<ans;
	return 0;
 } 
