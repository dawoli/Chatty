#include "bits/stdc++.h"
#include "vector"
using namespace std ; 
bool cmp(pair<int, double> a, pair<int, double> b) {return a.first < b.first ;}
int T ;
int n, m, L, V, d, v, a, ps[100005] ;
vector<pair<double, double> > p ;
int main()
{
	freopen("detect.in", "r", stdin) ;
	freopen("detect.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	for(int t = 1 ; t <= T ; ++t)
	{
		cin >> n >> m >> L >> V ;
		for(int i = 1 ; i <= n ; ++i)
		{
			cin >> d >> v >> a ;
			double x = a == 0 ? v > V ? L + 1 : -1 : d + (double)(V * V - v * v) / (2 * a) ;
			double y = a > 0 ? L + 1 : d == 0 ? -1 : d ;
			y = min((double)L + 1, y) ;
			y = max((double)-1, y) ;
			if(y < x) swap(x, y) ;
			p.push_back({x, y}) ;
		}
		sort(p.begin(), p.end(), cmp) ;
		for(int i = 1 ; i <= m ; ++i) cin >> ps[i] ;
		int p1 = 0, p2 = 1 ;
		while(1)
		{
			if(p1 >= p.size() || p2 >= m) break ;
			while(p[p1].first > ps[p2]) p2++ ;
			if(p[p1].second < ps[p2]) p.erase(p.begin() + p1), p1-- ;
			p1++ ;
		}
		cout << p.size() << " "	;
		for(int i = 0 ; i < p.size() ; ++i)
		{
			double x = p[i].first ;
			double y = p[i].second ;
			for(int j = 1 ; j < p.size() ; ++j)
			{
				if(i == j) continue ;
				if(p[j].first >= x && p[j].first <= y || p[j].second <= y && p[j].second >= x)
				{
					p[j].first = max(p[j].first, x) ;
					p[j].second = min(p[j].second, y) ;
					p.erase(p.begin() + i) ;
					--i ;
					break ;
				}
			}
		}
		cout << m - p.size() << endl ;
	}
	return 0 ;
}
// AC AC AC AC AC AC AC AC AC AC AC AC
//   STO OTZ sto orz STO OTZ sto orz
// AC AC AC AC AC AC AC AC AC AC AC AC
//          My dear CCF plz
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
