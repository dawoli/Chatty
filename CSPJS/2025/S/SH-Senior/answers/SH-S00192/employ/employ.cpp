#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int mod = 998244353;

bool vis[505];
int c[505],n,m,ans;
string s;

void dfs(int step,int cnt,int lost)
{
	if(step > n)
	{
		if(cnt >= m) ans++;
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(lost >= c[i]) dfs(step + 1,cnt,lost + 1);
			else
			{
				if(s[step - 1] == '0') dfs(step + 1,cnt,lost + 1);
				else dfs(step + 1,cnt + 1,lost);
			}
			vis[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	dfs(1,0,0);
	cout << ans;
	return 0;
}