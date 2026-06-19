#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 17;
struct Node
{
	int x, id;
	bool operator<(const Node&tmp) const
	{
		return x > tmp.x;	
	} 
}a[N * N];
int n, m;
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1, x; i <= n * m; i++)
		cin >> x, a[i].x = x, a[i].id = i;
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= m; i++) 
	{ 
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++)
				if(a[i * n - n + j].id == 1)
					return cout << i << " " << j, 0; 
		}else
			for(int j = n; j; j--)
				if(a[i * n - j + 1].id == 1)
					return cout << i << " " << j, 0;
	}
	return 0;
}
// ÉÙÓðÅ£±Æ
