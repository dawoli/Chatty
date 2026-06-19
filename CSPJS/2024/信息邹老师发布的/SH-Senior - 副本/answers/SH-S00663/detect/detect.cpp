#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int p[100010],fl[100010],fr[100010];
struct node{int x,y;}a[100010];
double eps = 1e-8;
bool cmp(node a,node b) {return a.x < b.x;}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,L;
		double V;
		cin >> n >> m >> L >> V;
		for(int i = 1;i <= n;i++)
		{
			int d,v,a;
			cin >> d >> v >> a;
			if(a > 0)
			{
				double s;
				if(v > V) s = 0;
				else s = v * (V - v) / a + 0.5 * (V - v) * (V - v) / a;
				s += d;
				//cout << i << 'a' << s << endl;
				if(abs(round(s) - s) < eps) fl[i] = round(s) + 1;
				else fl[i] = ceil(s);
				fr[i] = L;
			}
			else if(a == 0)
			{
				if(v > V)
				{
					fl[i] = d;
					fr[i] = L;
				}
				else
				{
					fl[i] = L + 1;
					fr[i] = 0;
				}
			}
			else
			{
				if(v > V)
				{
					double s = v * (V - v) / a + 0.5 * (V - v) * (V - v) / a;
					s += d;
					//cout << i << 'b' << s << endl;
					fl[i] = d;
					if(abs(round(s) - s) < eps) fr[i] = round(s) - 1;
					else fr[i] = floor(s);
				}
				else
				{
					fl[i] = L + 1;
					fr[i] = 0;
				}
			}
		}
		for(int i = 1;i <= m;i++) cin >> p[i];
		sort(p + 1,p + m + 1);
		int cnt = 0;
		for(int i = 1;i <= n;i++) if(fl[i] <= fr[i])
		{
			int bb,aa;
			if(fr[i] >= p[m]) bb = m;
			else bb = upper_bound(p + 1,p + m + 1,fr[i]) - p - 1;
			if(fl[i] > p[m]) continue;
			else aa = lower_bound(p + 1,p + m + 1,fl[i]) - p;
			//cout << i << ' ' << aa << ' ' << bb << ' ' << p[aa] << ' ' << p[bb] << ' ' << fl[i] << ' ' << fr[i] << endl;
			if(aa > bb) continue;
			a[++cnt] = {aa,bb};
		}
		cout << cnt << ' ';
		if(!cnt) cout << m << endl;
		else
		{
			sort(a + 1,a + cnt + 1,cmp);
			int now = a[1].y,ans = 0;
			for(int i = 2;i <= cnt;i++)
			{
				if(a[i].x > now)
				{
					ans++;
					now = a[i].y;
				}
				else now = min(now,a[i].y);
			}
			cout << m - ans - 1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
