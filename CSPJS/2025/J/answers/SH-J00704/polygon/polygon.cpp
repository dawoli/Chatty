#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 10;
int a[N];
int n;
int dfs (int i, int d, int step)
{
	if (step == 1)
	{
		int count = 0;
		for (int j = i; j <= n; j++)
		{
			if (a[j] > d)
			{
				count++;
			}
		}
		return count;
	}
	int sum = 0;
	for (int j = i; j <= n - step + 1; j++)
	{
		sum += dfs(j + 1,d - a[j],step - 1);
	}
	return sum;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int cnt = 0; 
	for (int i = 1; i < n; i++)
	{
		for (int length = 2; length <= n - 1; length++)
		{
			cnt += dfs(i + 1,a[i],length);
		}
	}
	cout<<cnt;
	return 0;
}
