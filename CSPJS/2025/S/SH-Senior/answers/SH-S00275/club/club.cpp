#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 9;
struct student{
	int a, b, c, f, s;
}a[_];
bool cmp(student x, student y)
{
	return x.f - x.s > y.f - y.s;
}
void init()
{
	for(int i = 1;i <= 1e5;i++)
		a[i].a = a[i].b = a[i].c = 0;
}
int get_from(int i, int num)
{
	if(a[i].a == num)
		return 1;
	if(a[i].b == num)
		return 2;
	return 3;
}
void doit()
{
	init();
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;
		a[i].f = max({ a[i].a, a[i].b, a[i].c });
		if(a[i].f == a[i].a)
			a[i].s = max(a[i].b, a[i].c);
		else if(a[i].f == a[i].b)
			a[i].s = max(a[i].a, a[i].c);
		else
			a[i].s = max(a[i].a, a[i].b);
	}
	sort(a + 1, a + n + 1, cmp);
	int cnt[4] = { 0, 0, 0, 0 };
	long long ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int f1 = get_from(i, a[i].f), f2 = get_from(i, a[i].s);
		if(cnt[f1] > n / 2 - 1)
			ans += a[i].s, cnt[f2]++;
		else
			ans += a[i].f, cnt[f1]++;
	}
	cout << ans << '\n';
	return;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
		doit();
	
	return 0;
}
