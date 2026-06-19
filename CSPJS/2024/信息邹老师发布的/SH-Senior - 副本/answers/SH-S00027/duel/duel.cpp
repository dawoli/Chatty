#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int NR = 100005;
int n, a[NR], ans = 0;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 2;
	while(r <= n)
	{
		if(a[r] > a[l])
		{
			ans++;
			l++;
			r++;
		}
		else r++;
	}
	cout << n-ans << endl;
	return 0;
}
