#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int T;
int n, m;
int len, V;
int p[N], d[N], v[N], a[N];
int ans1, ans2;
int pnow[N];

void opeo0()
{
	for (int i = 1; i <= n; i ++ ) 
	    if (d[i] <= p[m] && v[i] > V)
		     ans1 ++ ;
	if (!ans1) ans2 = m;
	else ans2 = m - 1;
	cout << ans1 << ' ' << ans2 << endl;	     
}

void opeopos()
{
	for (int i = 1; i <= n; i ++ )
	{
		if (p[m] < d[i]) continue;
		LL now = (LL)v[i] * v[i] + (LL)2 * (LL)a[i] * (p[m] - d[i]);
		if ((LL)V * V < now) ans1 ++ ; 
	}
	
	if (!ans1) ans2 = m;
	else ans2 = m - 1;
	cout << ans1 << ' ' << ans2 << endl;
}

void opeoneg()
{
	for (int i = 1; i <= n; i ++ )
	{
		if (v[i] <= V) continue;
		long double s = 1.l * ((LL)V * V - (LL)v[i] * v[i]) / a[i] / 2;
		int now = lower_bound(p + 1, p + 1 + m, d[i]) - p;
		//cout << p[now] << ' ' << d[i] << endl;
		if (p[now] < d[i]) continue;
		if (p[now] <= d[i] + s) ans1 ++ ;
	}
	
	if (!ans1)
	{
		cout << 0 << ' ' << m << endl;
		return ;
	}
	
	ans2 = 0;
	for (int state = 1; state < (1ll << m); state ++ )
	{
		int num = 0;
		for (int j = 0; j <= m; j ++ )
		    if ((state >> j) & 1)
		        pnow[ ++ num] = p[j + 1];
		//cout << state << ' ' << num << endl;        
		int res = 0;
	    for (int i = 1; i <= n; i ++ )
	    {
	    	if (a[i] >= 0) continue;
		    if (v[i] <= V) continue;
		    long double s = 1.l * (V * V - v[i] * v[i]) / a[i] / 2;
		    int now = lower_bound(pnow + 1, pnow + 1 + num, d[i]) - pnow;
		    if (pnow[now] < d[i]) continue;
		    if (pnow[now] <= d[i] + s) res ++ ;
	    }
	    if (res == ans1) ans2 = max(ans2, m - num);
	    //if (num == 1 && res == ans1) cout << p[num] << endl;
	} 
	
	cout << ans1 << ' ' << ans2 << endl;
}

void opeomix()
{
	for (int i = 1; i <= n; i ++ ) 
	    if (a[i] == 0 && d[i] <= p[m] && v[i] > V)
		     ans1 ++ ;
	int ag1 = ans1;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] <= 0) continue;
		if (p[m] < d[i]) continue;
		LL now = (LL)v[i] * v[i] + (LL)2 * (LL)a[i] * (p[m] - d[i]);
		if ((LL)V * V < now) ans1 ++ ; 
	}	     
	int ag2 = ans1;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] >= 0) continue;
		if (v[i] <= V) continue;
		long double s = 1.l * (V * V - v[i] * v[i]) / a[i] / 2;
		int now = lower_bound(p + 1, p + 1 + m, d[i]) - p;
		if (p[now] < d[i]) continue;
		if (p[now] <= d[i] + s) ans1 ++ ;
	}
	if (!ans1) 
	{
		cout << 0 << ' ' << m << endl;
		return ;
	}
	
	for (int state = 1; state < (1 << m); state ++ )
	{
		int num = 0;
		for (int j = 0; j < m; j ++ )
		    if (state >> j & 1)
		        pnow[ ++ num] = p[j + 1];
		int res = 0; 
		for (int i = 1; i <= n; i ++ ) 
	        if (a[i] == 0 && d[i] <= pnow[num] && v[i] > V)
		         res ++ ;
		if (res != ag1) continue;         
	    for (int i = 1; i <= n; i ++ )
	    {
		    if (a[i] <= 0) continue;
		    if (pnow[num] < d[i]) continue;
		    LL now = (LL)v[i] * v[i] + (LL)2 * (LL)a[i] * (pnow[num] - d[i]);
		    if ((LL)V * V < now) res ++ ; 
	    }	 		    
	    if (res != ag2) continue;
	    for (int i = 1; i <= n; i ++ )
	    {
	    	if (a[i] >= 0) continue;
		    if (v[i] <= V) continue;
		    long double s = 1.l * (V * V - v[i] * v[i]) / a[i] / 2;
		    int now = lower_bound(pnow + 1, pnow + 1 + num, d[i]) - pnow;
		    if (pnow[now] < d[i]) continue;
		    if (pnow[now] <= d[i] + s) res ++ ;
	    }
	    if (res == ans1) ans2 = max(ans2, m - num);
	    //if (num == 1 && res == ans1) cout << p[num] << endl;
	} 
	
	cout << ans1 << ' ' << ans2 << endl;
}

int main()
{
    freopen("detect.in", "r", stdin);	
    freopen("detect.out", "w", stdout);
	
	cin >> T;
	while (T -- )
	{
		ans1 = ans2 = 0;
		
		cin >> n >> m >> len >> V;
		bool al0 = true, alpos = true, alneg = true;; 
		for (int i = 1; i <= n; i ++ ) 
		{
			cin >> d[i] >> v[i] >> a[i];
			if (a[i] != 0) al0 = false;
			if (a[i] <= 0) alpos = false;
			if (a[i] >= 0) alneg = false;
		}
		for (int i = 1; i <= m; i ++ ) cin >> p[i];
		sort(p + 1, p + 1 + m);
		
		if (al0) opeo0();
		else if (alpos) opeopos();
		else if (alneg) opeoneg();
		else opeomix();
	}
	return 0;
}
