#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m; cin >> n >> m;
	for (int i = 1; i <= n * m; i++) scanf("%d" , &a[i]);
	int t = a[1];
	sort(a + 1 , a + n * m + 1);
	int k = n * m - (lower_bound(a + 1 , a + n * m + 1 , t) - a) + 1 , p = (k - 1) / n;
	cout << p + 1 << ' ' << (!(p & 1) ? k - p * n : (p + 1) * n + 1 - k);
	return 0;
}
