#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, L, V;
int d[100005], v[100005], a[100005];
int p[100005];
bool A, B, C;
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		A = true;
		B = true;
		C = true;
		int ans1 = 0, ans2 = 0;
		cin >> n >> m >> L >> V;
		for(int i = 0;i < n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0) A = false;
			if(a[i] > 0) C = false;
			if(a[i] < 0) B = false;
		}
		for(int i = 0;i < m;i++) cin >> p[i];
		if(A)
		{
			for(int i = 0;i < n;i++)
			{
				if(d[i] <= p[m - 1] && v[i] > V) ans1++;
			}
			cout << ans1 << " " << (ans1 == 0 ? m : m - 1) << endl;
			continue;
		}
		if(B)
		{
			for(int i = 0;i < n;i++)
			{
				if(d[i] <= p[m - 1] && sqrt(v[i] * v[i] + 2 * a[i] * (p[m - 1] - d[i])) > V) ans1++;
			}
			cout << ans1 << " " << (ans1 == 0 ? m : m - 1) << endl;
			continue;
		}
		cout << n / 2 << endl;
		cout << m / 2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
