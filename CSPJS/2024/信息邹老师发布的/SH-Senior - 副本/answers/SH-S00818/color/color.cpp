#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int p = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	p = c == '-' ? -1 : 1,c = getchar(); 
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
	return p * x;
}
void _write(int x)
{
	if(x > 9)	_write(x / 10);
	putchar(x % 10 | 48);
}
void write(int x)
{
	if(x < 0)
		putchar('-');
	write(abs(x));
}
void writeln(int x)
{
	write(x);
	puts("");
}
const int N = 2e5 + 10;
int n,a[N],T;
namespace Subtask1
{
	bool flag[N];
	int ans = 0;
	int score()
	{
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int cur = -1;
			for(int j = i - 1;j >= 1;j--)
				if(flag[j] == flag[i])
				{
					cur = j;
					break;
				}
			if(cur != -1 && a[i] == a[cur])
				ans += a[i]; 
		}
		return ans;
	}
	void dfs(int step)
	{
		if(step == n + 1)
		{
			ans = max(ans,score());
			return;
		}
		flag[step] = true;
		dfs(step + 1);
		flag[step] = false;
		dfs(step + 1);
	} 
	int _solve()
	{
		ans = 0;
		dfs(1);
		return ans;
	}
}
void solve()
{
	n = read();
	for(int i = 1;i <= n;i++)	a[i] = read();
	if(n <= 15)	cout << Subtask1::_solve() << endl;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T = read();
	while(T--)	solve();
	return 0;
}

