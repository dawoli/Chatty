#include <bits/stdc++.h>
using namespace std;

const int N=507,p=998244353;

int n,m,ans;
string s;
int c[N],vis[N];

void dfs(int step,int sum)
{
	if (sum>n-m)
		return;
	if (step>n)
	{
		ans++;
		ans%=p;
		return ;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=1;
			if (c[i]<=sum||s[step]=='0')
				dfs(step+1,sum+1);
			else
				dfs(step+1,sum);	
			vis[i]=0;
		}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	s=" "+s;
	for (int i=1;i<=n;i++)
		cin >> c[i];
	dfs(1,0);
	cout << ans << endl;
	return 0;
}
