#include <bits/stdc++.h>
using namespace std; 
int t, n, o, ans; 
struct T
{
	int sat[4], rk[4]; 
	int dsat()
	{
		return sat[0]-sat[1]; 
	}
} a[100009]; 
struct cmp
{
	bool operator() (T x, T y)
	{
		return x.dsat() > y.dsat(); 
	}
};
bool cmp2 (int x, int y)
{
	return a[o].sat[x] > a[o].sat[y]; 
}
priority_queue<T, vector<T>, cmp> pq[4]; 
int main ()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	cin >> t; 
	while (t--)
	{
		for (int i = 0; i < 3; i++)
		{
			while (!pq[i].empty()) pq[i].pop(); 
		}
		ans = 0; 
		cin >> n; 
		for (o = 0; o < n; o++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> a[o].sat[j]; 
				a[o].rk[j] = j; 
			}
			sort(a[o].rk, a[o].rk+3, cmp2); 
			sort(a[o].sat, a[o].sat+3, greater<int>()); 
			pq[a[o].rk[0]].push(a[o]); 
			ans += a[o].sat[0]; 
		}
		for (int i = 0; i < 3; i++)
		{
			while (pq[i].size()>n/2)
			{
				T x = pq[i].top(); 
				ans -= x.dsat(); 
				pq[i].pop(); 
			}
		}
		cout << ans << endl; 
	}
	return 0; 
}
