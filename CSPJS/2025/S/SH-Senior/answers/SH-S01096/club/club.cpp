#include<bits/stdc++.h>
using namespace std;
#define int long long

int a1[100010], a2[100010], a3[100010], n, answ = 0;

void fun(int cnt1, int cnt2, int cnt3, int ans, int x)
{
	if(n + 1 == x)
	{
		answ = max(answ, ans);
		return;
	}
	if(cnt1 > n/2) return; 
	if(cnt2 > n/2) return;
	if(cnt3 > n/2) return;
	fun(cnt1 + 1, cnt2, cnt3, ans + a1[x], x + 1); 
	fun(cnt1, cnt2 + 1, cnt3, ans + a2[x], x + 1); 
	fun(cnt1, cnt2, cnt3 + 1, ans + a3[x], x + 1);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		fun(0, 0, 0, 0, 1);
		cout << answ << endl;
	}
}
