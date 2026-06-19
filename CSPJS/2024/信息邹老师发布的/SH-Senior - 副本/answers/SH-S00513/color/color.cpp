#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[200005] = {};
int b[1000005] = {};
int c[200005] = {};
int maxn;
void dfs(int len,int num,int loc,int r,int b)
{
	if (loc == len + 1)
	{
		maxn = max(maxn,num);
		return;
	}
	dfs(len,num,loc + 1,r,b);
	if (c[loc] != 0)
	{
		if (loc >= r)
		{
			dfs(len,num + a[loc],loc + 1,c[loc],b);
		}
		else if (loc >= b)
		{
			dfs(len,num + a[loc],loc + 1,r,c[loc]);
		}
	}
	return;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i ++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		cin >> n;
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[j];
			if (b[a[j]] != 0)
			{
				c[b[a[j]]] = j;
			}
			b[a[j]] = j;
		}
		maxn = 0;
		dfs(n,0,1,0,0);
		cout << maxn << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
