#include<bits/stdc++.h>
using namespace std;
int n; // 小木棍数量 
int arr[5005] = {0}; // 小木棍长度
const int MOD = 998244353;
int ans = 0;

void dfs(int step, int maxx, int sum, int chooses)
{
	if(step == n + 1)
	{
		if(chooses < 3) return;
		if(sum <= 2 * maxx) return;
		ans++;
		ans %= MOD;
		return;
	}
	dfs(step + 1, maxx, sum, chooses);
	dfs(step + 1, max(maxx, arr[step]), sum + arr[step], chooses + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>arr[i];
	sort(arr + 1, arr + n + 1);
	dfs(1, 0, 0, 0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
