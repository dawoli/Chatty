#include<bits/stdc++.h>
const int N = 1e5 + 3;
struct S
{
	int a, b, c;
};
using namespace std;
int T, n, sum1, sum2, sum3;
vector<S> x, y, z;
bool cmp1(S s, S t)
{
	if(s.a != t.a)
		return s.a > t.a;
	if(s.b != t.b)
		return s.b < t.b;
	return s.c <= t.c;
}
bool cmp2(S s, S t)
{
	if(s.b != t.b)
		return s.b > t.b;
	if(s.a != t.a)
		return s.a < t.a;
	return s.c <= t.c;
}
bool cmp3(S s, S t)
{
	if(s.c != t.c)
		return s.c > t.c;
	if(s.a != t.a)
		return s.a < t.a;
	return s.b <= t.b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		long long ans = 0;
		cin >> n;
		S t;
		x.clear(), y.clear(), z.clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> t.a >> t.b >> t.c;
			int mx = max(t.a, max(t.b, t.c));
			if(mx == t.a)
			{
				sum1++;
				x.push_back(t);
				ans += t.a;
			}
			if(mx == t.b)
			{
				sum2++;
				y.push_back(t);
				ans += t.b;
			}
			if(mx == t.c)
			{
				sum3++;
				z.push_back(t);
				ans += t.c;
			}
		}
		if(sum1 <= n / 2 && sum2 <= n / 2 && sum3 <= n / 2)
		{
			cout << ans << '\n';
			continue;
		}
		sort(x.begin(), x.end(), cmp1);
		sort(y.begin(), y.end(), cmp2);
		sort(z.begin(), z.end(), cmp3);
		if(sum1 > n / 2)
			while(sum1 > n / 2)
			{
				ans -= x[sum1].a;
				ans += max(x[sum1].b, x[sum1].c);
				sum1--;
			}
		if(sum2 > n / 2)
			while(sum2 > n / 2)
			{
				ans -= y[sum2].a;
				ans += max(y[sum2].a, y[sum2].c);
				sum2--;
			}
		if(sum3 > n / 2)
			while(sum3 > n / 2)
			{
				ans -= z[sum3].c;
				ans += max(z[sum3].b, z[sum3].a);
				sum3--;
			}
		cout << ans << '\n';
	}
	/*
	晋太元中，武陵人捕鱼为业，缘溪行，忘路之远近。忽逢桃花林，夹岸数百步，中无杂树，芳草鲜美，落英缤纷。渔人甚异之，复前行，欲穷其林。
	林尽水源，便得一山。山有小口，仿佛若有光。便舍船，从口入。初极狭，才通人，复行数十步，豁然开朗。土地平旷，屋舍俨然，有良田、美池、桑竹之属，阡陌交通，鸡犬相闻。其中往来种作，男女衣着，悉如外人。黄发垂髫，并怡然自乐。 
	*/ 
	return 0;
 } 
