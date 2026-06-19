#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffrr.out","w",stdout);
	int T;
	cin >> T;
	while(T --)
	{
		int sum = 0;
		for(int i = 1;i <= 5;i ++)
		{
			for(int j = 1;j <= 8;j ++)
			{	string cl;
				cin >> cl;
				if(cl == "math")
				{
					a[i] ++;
				}
			}
			sum += a[i];
		}
		int n, m;
		cin >> n >> m;
//		for(int i = 1;i <= 5;i ++)
//			cout << a[i] << '\n';
		int cnt = n / 7;
		if(n % 7 == 0)
		{
			cout << 1ll * sum * cnt << '\n';
			for(int i = 1;i <= 5;i ++)
				a[i] = 0;
			continue;
		}
		long long ans = 1ll * sum * cnt;
		for(int i = 0;i < n % 7;i ++)
		{
			int v = m + i;
			if(v > 7)
			{
				v %= 7;
			}
			ans += 1ll * a[v];
		}
		cout << ans << '\n';
		for(int i = 1;i <= 5;i ++)
			a[i] = 0;
	}
	return 0;
} 
