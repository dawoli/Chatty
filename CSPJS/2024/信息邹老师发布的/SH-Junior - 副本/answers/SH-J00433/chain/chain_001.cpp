#include<bits/stdc++.h>
using namespace std;

int t;
const int N = 2 * 1e5 + 10;

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin>>t;
	while(t--)
	{
		int n, k, q;
		cin>>n>>k>>q;
		int arr[N][N], tasks[5][N];
		for(int i = 1; i <= n; i++)
		{
			cin>>arr[i][0];
			for(int j = 1; j <= arr[i][0]; j++)
			{
				cin>>arr[i][j];
			}
		}
		for(int i = 1; i <= q; i++)
		{
			cin>>tasks[i][1]>>tasks[i][2];
		}
	}
	return 0;
}
