#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6+5;
int T;
int x;
int a[maxn];
int num[maxn];
int n;
vector <int> v; 
int ans = 0;

int main ()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		ans = 0;
		memset(num, 0, sizeof(num));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			//cin >> a[i];
			cin >> x;
			num[x]++;
			if (num[x] == 2)
			{
				//v.pushback(i);
				ans+=x;
			}
		}
		/*
		for (int = 0; i < v.size(); i++)
		{
			ans++;
		}
		*/
		cout << ans << endl;
	}
	
	
	return 0;
}
