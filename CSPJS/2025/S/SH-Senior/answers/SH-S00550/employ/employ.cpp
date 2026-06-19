#include <bits/stdc++.h>
using namespace std;
int calc(int p)
{
	long long res = 2;
	for (int i = 3; i <= p; i++)
	{
		res = (res*i)%998244353;
	}
	return res;
}	
char s[505];
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin >> n >> m;
	bool spec_a = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i]=='0') spec_a = 0;
	}
	if (n <= 11)
	{
		int anss = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int t = calc(n);
		//cout << t << '\n';
		int tst[20];
		for (int i = 1; i <= n; i++)
		{
			tst[i] = i;
		}
		for (int i = 1; i <= t; i++)
		{
			if (i > 1) next_permutation(tst+1,tst+n+1);
			int cn = 0, failure = 0;
			bool fff = 0;
			for (int j = 1; j <= n; j++)
			{
				int l = tst[j];
				int c = a[l];
				//cout << i << ' ' << j << ' ' << cn << ' ' << c << '\n';
				if (cn >= c || s[j]=='0')
				{
					cn++;
					failure++;
					if (n-failure < m)
					{
						fff = 1;
						break;
					}
				}
			}
			if (n-failure >= m) anss++;
		}
		cout << anss << endl;
		return 0;
	}
	if (spec_a)
	{
		int cnta = 0;
//		priority_queue<int, vector<int>, greater<int> > q;
		//cerr << "SPECIAL TYPE: A\n";
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] > 0) 
			{
				cnta++;
				//q.push(a[i]);
			}
		}
		if (cnta >= m)
		{
//			int acnt = n-cnta;
//			while (!q.empty() && cnta >= m)
//			{
//				if (q.top()>acnt) break;
//				q.pop();
//				cnta--;
//				acnt++;
//			}
			//if (cnta < m || q.empty()) cout << 0;
			//else
			//{
				cout << calc(n);
			//}
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
