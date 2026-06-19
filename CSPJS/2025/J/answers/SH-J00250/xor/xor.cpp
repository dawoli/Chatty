#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
int a[10005];
int sum[10005][10005];
bool f1 = 1;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] == k)
		{
			cnt++; //值与权值相等则直接计数 
		}
		if (a[i] != 1) f1 = 0;
	}
	
	if (f1 && k == 0)
	{
		cout << n/2;
		return 0;
	} //性质A 
	
	for (long long i = 1; i <= n; ++i)
	{
		if (a[i] == k) continue;
		sum[i][i] = a[i];
		for (int j = i+1; j <= n; ++j)
		{
			if (a[j] == k) break;
			sum[i][j] = sum[i][j-1] ^ a[j];
			if (sum[i][j] == k)
			{
				cnt++;
				sum[i][j] = a[i];
			}
		}
	}
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
