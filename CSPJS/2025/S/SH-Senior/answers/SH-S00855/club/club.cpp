#include <bits/stdc++.h>
using namespace std;
int T;
int n, hfn;
int s1[100009], s2[100009], s3[100009];
vector <int> a1;
vector <int> a2;
vector <int> a3;
int mincost[100009];
//int pos[100009];
int v1, v2, v3;
long long sum = 0;
int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}
void input()
{
	cin >> n;
	hfn = n / 2;
	int sat1, sat2, sat3;
	for (int i = 1; i <= n; i++)
	{
		cin >> sat1 >> sat2 >> sat3;
		s1[i] = sat1;
		s2[i] = sat2;
		s3[i] = sat3;
		int maxsat = max3(sat1, sat2, sat3);
		sum += maxsat;
		if (maxsat == sat1)
		{
			//v1++;
			//pos[i] = 1;
			a1.push_back(i);
		}
		else if (maxsat == sat2)
		{
			//v2++;
			//pos[i] = 2;
			a2.push_back(i);
		}
		else
		{
			//v3++;
			//pos[i] = 3;
			a3.push_back(i);
		}
	}
}

void calccost(int k)
{
	if (k == 1)
	{
		for (int i = 0, j = 1; i < a1.size(); i++, j++)
		{
			int id = a1[i];
			mincost[j] = min(s1[id] - s2[id], s1[id] - s3[id]);
		}
		sort (mincost + 1, mincost + 1 + v1);
		for (int i = 1; i <= v1 - hfn; i++)
		{
			sum -= mincost[i];
		}
	}
	else if (k == 2)
	{
		for (int i = 0, j = 1; i < a2.size(); i++, j++)
		{
			int id = a2[i];
			mincost[j] = min(s2[id] - s1[id], s2[id] - s3[id]);
		}
		sort (mincost + 1, mincost + 1 + v2);
		for (int i = 1; i <= v2 - hfn; i++)
		{
			sum -= mincost[i];
		}
	}
	else
	{
		for (int i = 0, j = 1; i < a3.size(); i++, j++)
		{
			int id = a3[i];
			mincost[j] = min(s3[id] - s1[id], s3[id] - s2[id]);
		}
		sort (mincost + 1, mincost + 1 + v3);
		for (int i = 1; i <= v3 - hfn; i++)
		{
			sum -= mincost[i];
		}	
	}
}
void solve()
{
	v1 = a1.size();
	v2 = a2.size();
	v3 = a3.size();
	if (v1 <= hfn && v2 <= hfn && v3 <= hfn)
	{
		cout << sum << endl;
//		cout << "nocalc" << endl;
		return;
	}
	if (v1 > hfn)
	{
		calccost(1);
//		cout << "calc1" << endl;
	}
	else if (v2 > hfn)
	{
		calccost(2);
//		cout << "calc2" << endl;
	}
	else
	{
		calccost(3);
//		cout << "calc3" << endl;
	}
	cout << sum << endl;
	return;
}

void init()
{
	n = 0;
	sum = 0;
	v1 = v2 = v3 = 0;
	a1.clear();
	a2.clear();
	a3.clear();
	for (int i = 1; i <= n; i++)
	{
		s1[i] = s2[i] = s3[i] = 0;
		mincost[i] = 0;
	}
}
int main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		input();
		solve();
		init();
	}
	return 0;
}
