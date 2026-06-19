#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 8;
const int MAXL = 1e6 + 8;
struct node
{
	int d, v, a, st, et;
	bool cfp;//是否超速 
	bool can_be_check;//超速行为能否被检测到 
}cars[MAXN];
struct furtherm
{
	int slen, elen;
	bool operator<(const furtherm& rhs) const
	{
		return rhs.slen > slen;
	}
}lscars[MAXN];
int monitors[MAXN];
int whmt[MAXL];
bool cmp(furtherm x, furtherm y)
{
	return x.elen > y.elen;
}
bool cmp2(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, roadl, rule;
		scanf("%d%d%d%d", &n, &m, &roadl, &rule);
		for (int i = 0; i < MAXN; i++)
		{
			cars[i].d = 0;
			cars[i].a = 0;
			cars[i].v = 0;
			cars[i].cfp = 0;
			cars[i].et = 0;
			cars[i].st = 0;
			cars[i].can_be_check = 0;
			lscars[i].elen = 0;
			lscars[i].slen = 0;
		}
		memset(monitors, 0, sizeof(monitors));
		memset(whmt, 0, sizeof(whmt));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &cars[i].d, &cars[i].v, &cars[i].a);
			int cd = cars[i].d, cv = cars[i].v, ca = cars[i].a;//等于不算超速 
			//计算起始与结束位置
			if (ca > 0)
			{
				if (cv > rule)
				{
					cars[i].st = cd;
					cars[i].et = roadl + 1;
					cars[i].cfp = 1;
				}
				else
				{
					int tr = rule * rule - cv * cv, er = 2 * ca;
					int yr;
					if (tr % er == 0)
					{
						yr = tr / er + 1;
					}
					else
					{
						yr = ceil(tr * 1.0 / er);
					}
					if (yr + cd <= roadl)
					{
						cars[i].cfp = 1;
						cars[i].st = yr + cd;
						cars[i].et = roadl + 1;
					}
					else
					{
						cars[i].cfp = 0;
					}
				}
			}
			else if (ca < 0)
			{
				if (cv <= rule)
				{
					cars[i].cfp = 0;
				}
				else
				{
					int tr = cv * cv - rule * rule, er = -2 * ca;
					int yr;
					if (tr % er == 0)
					{
						yr = tr / er - 1;
					}
					else
					{
						yr = floor(tr * 1.0 / er);
					}
					cars[i].cfp = 1;
					cars[i].st = cd;
					cars[i].et = min(cd + yr, roadl + 1);
				}
			}
			else
			{
				if (cv <= rule)
				{
					cars[i].cfp = 0;
				}
				else
				{
					cars[i].cfp = 1;
					cars[i].st = cd;
					cars[i].et = roadl + 1;
				}
			}
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &monitors[i]);
			whmt[monitors[i]]++;
		}
		for (int i = 1; i <= roadl + 5; i++)
		{
			whmt[i] = whmt[i - 1] + whmt[i];
		}
		int nnum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cars[i].cfp == 1)
			{
				if (whmt[cars[i].et] - whmt[cars[i].st - 1] >= 1)
				{
					cars[i].can_be_check = 1;
					nnum++;
					lscars[nnum].slen = cars[i].st;
					lscars[nnum].elen = cars[i].et;
				}
			}
		}
		cout << nnum << " ";
		sort(lscars + 1, lscars + nnum + 1, cmp);
		sort(monitors + 1, monitors + m + 1, cmp2);
		int pisk = 1;
		int cur_monitor;
		priority_queue <furtherm> q;
		int ans2 = 0;
		for (int i = 1; i <= m; i++)
		{
			cur_monitor = monitors[i];
			while (lscars[pisk].elen > cur_monitor && pisk <= nnum)
			{
				q.push(lscars[pisk]);
				pisk++;
			}
			if (!q.empty())
			{
				if (monitors[i + 1] < q.top().slen)//选择当前摄像头 
				{
					ans2++;
					while (!q.empty()) q.pop();
				}
			}
		}
		cout << m - ans2 << endl;
	}
 	return 0;
}
