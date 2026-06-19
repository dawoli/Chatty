#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
#define MXN 500005
#define LGN 20
using namespace std;
int n, x, ans = 514514;
bool a[MXN][LGN];
void work(int x, int p)
{
	for(int i = 0; i < LGN; i++)
		a[p][i] = (x >> i) % 2;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n;
	for(int i = 0; i <= n; i++)
		scanf("%d", &x), work(x, i);
	for(int i = 0; i < LGN; i++)
	{
		int cnt = 0;
		if(a[0][i])    //k[i] == 1
		{
			for(int j = 1; j <= n; j++)
				if(a[j][i])
					cnt++;
		}
		else           //k[i] == 0
		{
			for(int j = 1; j <= n; j++)
				if((j > 1 && a[j][i] && a[j - 1][i]) || (!a[j][i]))
					cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}
//please put me on the QIPADASHANG (LG UID: 1029108)
//30-100pts
