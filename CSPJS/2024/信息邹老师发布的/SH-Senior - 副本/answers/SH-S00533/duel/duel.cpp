#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5; 
int n,a[N],cnt;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1])
		{
			int l = lower_bound(a + 1,a + n + 1,a[i - 1]) - a;
			int r = upper_bound(a + 1,a + n + 1,a[i - 1]) - a;
			cnt += r - l;
		}
		if (cnt) cnt--;
	}
	int l = lower_bound(a + 1,a + n + 1,a[n]) - a;
	int r = upper_bound(a + 1,a + n + 1,a[n]) - a;
	cnt += r - l;
	cout << cnt;
	return 0;
}
//1 1 2 2 3
