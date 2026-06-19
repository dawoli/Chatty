#include <bits/stdc++.h>
using namespace std; 
const int N = 510;
int n,m;
string ss;
bool s[N];
int c[N];
const int P = 998244353;
int p[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin >> n >> m;
	cin >> ss;
	for(int t = 0;t < n;t++)
	{
		s[t + 1] = bool(ss[t] - '0');
	}
	for(int t = 1;t <= n;t++)
	{
		cin >> c[t];
		p[t] = t;
	}
	if(n <= 18)
	{
		long long ans = 0;
		do
		{
			int gp = 0;
			int sc = 0; 
//			for(int t = 1;t <= n;t++)
//			{
//				cout << p[t] << " ";
//			}
//			cout << endl;
			for(int t = 1;t <= n;t++)
			{
				if(gp >= c[p[t]])
				{
					gp++; 
				}
				else if(s[t])
				{
					sc++;
				}
				else gp++;
				//cout << sc << " " << gp << endl;
			}
			if(sc >= m)
			{
				ans++;
				ans %= P;
				//cout << endl;
			}
		}while(next_permutation(p + 1,p + n + 1));
		cout << ans;
	}
	else
	{
		long long ans = 1;
		for(int t = 1;t <= n;t++)
		{
			ans *= t; 
			ans %= P; 
		}
		cout << ans;
	}
	return 0;
}
