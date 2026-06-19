#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int p = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	p = c == '-' ? -1 : 1,c = getchar(); 
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
	return p * x;
}
void _write(int x)
{
	if(x > 9)	_write(x / 10);
	putchar(x % 10 | 48);
}
void write(int x)
{
	if(x < 0)
		putchar('-');
	write(abs(x));
}
void writeln(int x)
{
	write(x);
	puts("");
}
int n,m,L,V;
const int N = 1e5 + 10;
double l[N],r[N],t[N];
int d[N],v[N],a[N],p[N];
double _round(double x) { return ((int)(x / 1e-6)) * 1e-6; }
bool flag[N];
int s[N];
vector<int> vec[N];
int ans = 21e8;
bool check()
{
	for(int i = 1;i <= m;i++)
	{
		if(vec[i].size() == 0)	continue;
		int cnt = 0;
//		for(int j = 0;j < vec[i].size();j++)
//			cnt += flag[j];
		cnt += s[vec[i].back()] - s[vec[i][0] - 1];
		if(cnt == 0)	return false;
	}
	return true;
}
void dfs(int step,int cnt = 0)
{
	if(step == n + 1)
	{
		if(check())	ans = min(ans,cnt);
		return;
	}
	flag[step] = true;
	s[step] = s[step - 1] + 1;
	dfs(step + 1,cnt + 1);
	flag[step] = false;
	s[step] = s[step - 1];
	dfs(step + 1,cnt);
	s[step] = 0;
}
void solve()
{
	cin >> n >> m >> L >> V;
	for(int i = 1;i <= n;i++)
	{
		vec[i].clear();
		cin >> d[i] >> v[i] >> a[i];
		if(a[i] == 0)
			l[i] = d[i],r[i] = L,t[i] = (L - d[i]) * 1.0 / v[i];
		else
		{
			t[i] = min((sqrt(v[i] * v[i] - 2 * a[i] * d[i] + 2 * a[i] * L) - v[i]) * 1.0 / a[i],-v[i] * 1.0 / a[i]);
			t[i] = _round(t[i]);
			l[i] = d[i];
			r[i] = d[i] + v[i] * t[i] + 0.5 * a[i] * t[i] * t[i];
			r[i] = _round(r[i]);
			if(t[i] != -v[i] * 1.0 / a[i])	r[i] = r[i] + 1;
		}
	}
	for(int i = 1;i <= m;i++)	cin >> p[i];
	sort(p + 1,p + m + 1);
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			if(!(l[i] <= p[i] && p[i] < r[i]))	continue;
			double vv = sqrt(v[j] * v[j] - 2 * a[j] * p[i] - 2 * a[j] * l[j]);
			vv = _round(vv);
			if(p[i] * 1.0 < vv)
				vec[j].push_back(i);
		}
	ans = 21e8;
	dfs(1);
	int ans1 = 0;
	for(int i = 1;i <= n;i++)
		ans1 += vec[i].size() != 0;
	cout << ans1 << " " << ans << endl;
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin >> T;
	while(T--)	solve();
	return 0;
}

