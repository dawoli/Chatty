#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[510];
string s;
const int qumoshu = 998244353;
int dfsAns = 0;
bool ok[510];

template <typename T> void read(T &t)
{
	char c = getchar();
	int f = 1;
	t = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		t = (t << 3) + (t << 1) + (c ^ 48);
		c = getchar();
	}
	t *= f;
}

bool cmp(int x,int y)
{
	return x > y;
}

void dfs(int pos,int alrOk,int alrNo)
{
	if(pos == n + 1)
	{
		if(alrOk >= m)
		{
			dfsAns++;
			dfsAns %= qumoshu;
		}
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(ok[i])
			continue;
		if(s[pos - 1] == '1' && alrNo < c[i])
		{
			ok[i] = true;
			dfs(pos + 1,alrOk + 1,alrNo);
			ok[i] = false;
		}
		else
		{
			ok[i] = true;
			dfs(pos + 1,alrOk,alrNo + 1);
			ok[i] = false;
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	cin >> s;
	bool flag = false,quanyi = true;
	int zeroNum = 0;
	for(int i = 1; i <= n; i++)
	{
		read(c[i]);
		if(c[i] == 0)
			zeroNum++,flag = true;
	}
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '0')
		{
			quanyi = false;
			break;
		}
	}
	if(n <= 10)
	{
		memset(ok,0,sizeof(ok));
		dfs(1,0,0);
		cout << dfsAns << '\n';
		return 0;
	}
	else if(m == n)
	{
		if(flag || !quanyi)
			cout << 0 << '\n';
		else
		{
			int ret = 1;
			for(int i = 2; i <= n; i++)
				ret = (ret * i) % qumoshu;
			cout << ret << '\n';
		}
		return 0;
	}
	else
	{
		memset(ok,0,sizeof(ok));
		dfs(1,0,0);
		cout << dfsAns << '\n';
	}
	return 0;
}
