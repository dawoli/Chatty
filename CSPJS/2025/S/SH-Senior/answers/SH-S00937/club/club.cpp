#include <bits/stdc++.h>
using namespace std;
int zero(int num)
{
	return (num == 0 ? 1 : 0);
}
struct stu
{
	int a, b, c;
	bool operator<(stu other)
	{
		int szeros = zero(a) + zero(b) + zero(c);
		int ozeros = zero(other.a) + zero(other.b) + zero(other.c);
		if (szeros != ozeros)
			return szeros > ozeros;
		if (szeros == 2)
		{
			return max(a, max(b, c)) > max(other.a, max(other.b, other.c));
		}
		if (szeros == 1)
		{
			int tsa, tsb;
			if (a != 0)
				tsa = a;
			if (b != 0)
			{
				if (a == 0)
					tsa = b;
				else
					tsb = b;
			}
			if (c != 0)
				tsb = c;
			int toa, tob;
			if (other.a != 0)
				toa = other.a;
			if (other.b != 0)
			{
				if (other.a == 0)
					toa = b;
				else
					tob = b;
			}
			if (other.c != 0)
				tob = c;
			if (abs(tsa - tsb) != abs(toa - tob))
				return abs(tsa - tsb) > abs(toa - tob);
			return tsa + tsb > toa + tob;
		}
		double sa = a + 0.1, sb = b + 0.1, sc = c + 0.1;
		double oa = other.a + 0.1, ob = other.b + 0.1, oc = other.c + 0.1;
		return (sa / sb + sb / sc + sc / sa) > (oa / ob + ob / oc + oc / oa);
	}
} students[100005];
void solve()
{
	int n;
	cin >> n;
	int m = n / 2;
	for (int i = 0, a, b, c; i < n; ++i)
	{
		cin >> a >> b >> c;
		students[i].a = a;
		students[i].b = b;
		students[i].c = c;
	}
	sort(students, students + n);
	int a = 0, b = 0, c = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (zero(students[i].a) + zero(students[i].b) + zero(students[i].c) == 2)
		{
			if (students[i].a != 0 && a < m)
			    ++a, ans += students[i].a;
			else if (students[i].b != 0 && b < m)
				++b, ans += students[i].b;
			else
				++c, students[i].c;
		}
		else if (zero(students[i].a) + zero(students[i].b) + zero(students[i].c) == 1)
		{
			char f, s;
			int first = max(students[i].a, max(students[i].b, students[i].c)), second;
			if (first == students[i].a)
				second = max(students[i].b, students[i].c), f = 'a';
			else if (first == students[i].b)
				second = max(students[i].a, students[i].c), f = 'b';
			else
				second = max(students[i].a, students[i].b), f = 'c';
			if (f == 'a' && a < m)
				++a, ans += first;
			else if (f == 'b' && b < m)
				++b, ans += first;
			else if (f == 'c' && c < m)
				++c, ans += first;
			else if (second == students[i].a && a < m)
				++a, ans += second;
			else if (second == students[i].b && b < m)
			    ++b, ans += second;
			else if (second == students[i].c && c < m)
				++c, ans += second;
			else
			{
				if (a < m)
					++a;
				else if (b < m)
					++b;
				else
					++c;
			}
		}
		else
		{
			int aa = -1, ab = -1, ac = -1;
			aa = (a < m) * (ans + students[i].a);
			ab = (b < m) * (ans + students[i].b);
			ac = (c < m) * (ans + students[i].c);
			int tmp = max(aa, max(ab, ac));
			if (tmp == aa)
				++a, ans += students[i].a;
			else if (tmp == ab)
				++b, ans += students[i].b;
			else
				++c, ans += students[i].c;
		}
	}
	cout << ans << "\n";
}
/*int n, m, ans;
char vst[31];
void dfs(int d)
{
	if (d == n)
	{
		int tmp = 0;
		for (int i = 0, a, b, c; i < n; ++i)
		{
			cout << vst[i] << ' ';
			if (vst[i] == 'a')
				++a, tmp += students[i].a;
			if (vst[i] == 'b')
				++b, tmp += students[i].b;
			if (vst[i] == 'c')
				++c, tmp += students[i].c;
			if (a > m || b > m || c > m)
				return;
		}
		cout << tmp;
		ans = max(ans, tmp);
		return;
	}
	vst[d] = 'a';
	dfs(d + 1);
	vst[d] = 'b';
	dfs(d + 1);
	vst[d] = 'c';
	dfs(d + 1);
}
void solve()
{
	cin >> n;
	m = n / 2;
	for (int i = 0, a, b, c; i < n; ++i)
	{
		cin >> a >> b >> c;
		students[i].a = a;
		students[i].b = b;
		students[i].c = c;
	}
	ans = -1;
	dfs(0);
	cout << ans << endl;
}*/
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}

