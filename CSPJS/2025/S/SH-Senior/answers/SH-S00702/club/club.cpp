#include<bits/stdc++.h>
#define maxn 100020
#define inf 0x3f3f3f3f 
using namespace std;

int t, n;
int a[maxn][5], zuiduo;
int maxxx[maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf ("%d", &t);
	while (t--)
	{
		int ans = 0;
		scanf ("%d", &n);
		zuiduo=n/2;
		for (int i = 1; i <= n; i++)
		{
		
			scanf ("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			maxxx[i] = max(max(a[i][1], a[i][2]), a[i][3]);
			ans += maxxx[i];
		}
	

		
		printf ("%d\n", ans);	
	}
	
	return 0;
}





