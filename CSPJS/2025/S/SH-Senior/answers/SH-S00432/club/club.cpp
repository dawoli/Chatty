#include<iostream>
#include<algorithm>
using namespace std;
int b[3][100005] , cnt[3];
void solve()
{
	int n; scanf("%d" , &n);
	cnt[0] = cnt[1] = cnt[2] = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int a[3]; scanf("%d%d%d" , &a[0] , &a[1] , &a[2]);
		int t = max(a[0] , max(a[1] , a[2]));
		sum += t;
		if (t > a[1] && t > a[2]) b[0][++ cnt[0]] = a[0] - max(a[1] , a[2]);
		else if (t > a[0] && t > a[2]) b[1][++ cnt[1]] = a[1] - max(a[0] , a[2]);
		else if (t > a[0] && t > a[1]) b[2][++ cnt[2]] = a[2] - max(a[0] , a[1]);
	}
	int k = -1;
	if (cnt[0] > (n >> 1)) k = 0;
	else if (cnt[1] > (n >> 1)) k = 1;
	else if (cnt[2] > (n >> 1)) k = 2;
	if (k != -1)
	{
		sort(b[k] + 1 , b[k] + cnt[k] + 1);
		for (int i = 1; i <= cnt[k] - (n >> 1); i++) sum -= b[k][i];
	}
	printf("%d\n" , sum);
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t; cin >> t;
	while (t --) solve();
	return 0;
} 
