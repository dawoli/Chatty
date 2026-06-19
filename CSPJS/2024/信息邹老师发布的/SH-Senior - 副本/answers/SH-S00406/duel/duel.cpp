#include<iostream>
using namespace std;
const int m = 1e5;
int r[100005] , cnt[100005];
int main()
{
	freopen("duel.in" , "r" , stdin);
	freopen("duel.out" , "w" , stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n; i++) cnt[r[i]] ++;
	for (int i = 1; i <= m; i++)
	cnt[i] += max(0 , cnt[i - 1] - cnt[i]);
	cout << cnt[m];
	return 0;
}
