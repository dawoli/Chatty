#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n,a[N],cnt = 0;
vector <int> ans;

void dfs(int start,int total)
{
	if (n-start+1 < total) return;
	if (total == 0) 
	{
		int maxn = 0,sum = 0;
		for (int i : ans)
		{
			maxn = max(maxn,i);
			sum += i;
		}
		if (sum > 2*maxn)
		{
			cnt++;
			cnt %= 998244353;
		}
		return;
	}
	ans.push_back(a[start]);
	dfs(start+1,total-1);
	ans.pop_back();
	dfs(start+1,total);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 3;i <= n;i++)
	{
		dfs(1,i);
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
