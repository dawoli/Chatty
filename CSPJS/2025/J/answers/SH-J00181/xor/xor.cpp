#include<bits/stdc++.h>
const int N = 1e3 + 3; 
using namespace std;
int n, k, a[N], sum[N], f[N][N];
int main()
{
	freopen("xor.in","r",stdin); // 我爱陈珝心 
	freopen("xor.out","w",stdout); // 我爱陈珝心
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if((sum[j] ^ sum[i - 1]) == k)
			{
				f[i][j] = 1;
			}
	for(int i = 1; i < n; i++)
		for(int l = 1; i + l <= n; l++)
		{
			int r = i + l;
			for(int j = l; j < r; j++)
				f[l][r] = max(f[l][r], f[l][j] + f[j + 1][r]);
		}
	cout << f[1][n];
	return 0;
}
