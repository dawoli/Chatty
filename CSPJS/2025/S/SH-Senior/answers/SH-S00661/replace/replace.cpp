#include<bits/stdc++.h>
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 10, M = 5e6 + 10, P1 = 998244353, P2 = 1e9 + 7, B = 29;

struct node
{
	string a, b;
	int id, sum;
};

int n, q, tot;
int pw1[M], pw2[M];
int ans[N];
string a[N], b[N];
ull c[N], d[N];
string s1, s2;
vector<node> p[N];
map<pair<ull, ull>, int> mp;

ull hsh(string s)
{
	int len = s.length();
	ull x = 0, y = 0;
	for (int i = 0; i < len; i++)
	{
		x += (s[i] - 'a' + 1) * pw1[i] % P1;
		y += (s[i] - 'a' + 1) * pw2[i] % P2;
	}
	return y * P1 + x;
}

bool cmp(node x, node y)
{
	if (x.a == y.a)
	{
		return x.b < y.b;
	}
	return x.a < y.a;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= 5e6; i++)
	{
		pw1[i] = pw1[i - 1] * B % P1;
		pw2[i] = pw2[i - 1] * B % P2;
	}
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1 >> s2;
		int len = s1.length();
		int l, r;
		for (int j = 0; j < len; j++)
		{
			if (s1[j] != s2[j])
			{
				l = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; j--)
		{
			if (s1[j] != s2[j])
			{
				r = j;
				break;
			}
		}
		a[i] = s1.substr(0, l);
		reverse(a[i].begin(), a[i].end());
		b[i] = s1.substr(r + 1, len - r);
		c[i] = hsh(s1.substr(l, r - l + 1));
		d[i] = hsh(s2.substr(l, r - l + 1));
//		cout << a[i] << " " << b[i] <<" "<<s1.substr(l, r - l + 1)<<" "<<s2.substr(l, r - l + 1)<< endl;
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> s1 >> s2;
		int len = s1.length();
		int l, r;
		
		for (int j = 0; j < len; j++)
		{
			if (s1[j] != s2[j])
			{
				l = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; j--)
		{
			if (s1[j] != s2[j])
			{
				r = j;
				break;
			}
		}
		node tmp;
		tmp.a = s1.substr(0, l);
		reverse(tmp.a.begin(), tmp.a.end());
		tmp.b = s1.substr(r + 1, len - r);
		tmp.id = i;
		ull cc = hsh(s1.substr(l, r - l + 1));
		ull dd = hsh(s2.substr(l, r - l + 1));
		if (!mp.count(make_pair(cc, dd)))
		{
//			cout << cc << " " << dd << " " << i << endl;
			mp[make_pair(cc, dd)] = ++tot;
			p[tot].push_back(tmp);
		}
		else
		{
//			cout << cc << " " << dd << " " << i << endl;
			p[mp[make_pair(cc, dd)]].push_back(tmp);
		}
//		cout << tmp.a << " " << tmp.b <<" "<<s1.substr(l, r - l + 1)<<" "<<s2.substr(l, r - l + 1)<< endl;
	}
	for (int i = 1; i <= tot; i++)
	{
		sort(p[i].begin(), p[i].end(), cmp);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!mp.count(make_pair(c[i], d[i])))
		{
			continue;
		}
		int k = mp[make_pair(c[i], d[i])];
		int len = p[k].size() - 1;
//		cout <<"l:"<< len << endl;
		int l = 0, r = len, res = -1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (p[k][mid].a >= a[i])
			{
				res = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
//		cout << res << endl;
		if (res == -1)
		{
			continue;
		}
		int la = a[i].size() - 1, lb = b[i].size() - 1;
		for (int j = res; j <= len; j++)
		{
//			cout <<"kkk: "<< p[k][j].a.substr(0, la + 1) << " " << a[i]<< " " << p[k][j].b.substr(0, lb + 1) << " " << b[i]<< endl;
			if (p[k][j].a.substr(0, la + 1) != a[i])
			{
				break;
			}
			if (p[k][j].b.substr(0, lb + 1) == b[i])
			{
				p[k][j].sum++;
			}
		}
	}
	for (int i = 1; i <= tot; i++)
	{
		int len = p[i].size() - 1;
		for (int j = 0; j <= len; j++)
		{
			ans[p[i][j].id] = p[i][j].sum;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
} 
