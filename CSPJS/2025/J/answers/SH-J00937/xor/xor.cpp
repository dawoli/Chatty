#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> v(n+1,0);
	bool is1 = true,is1or0 = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> v[i];
		if(v[i] != 1)
		{
			is1 = false;
			if(v[i] != 0)
			{
				is1or0 = false;
			}
		}
	}
	if(is1)
	{
		cout << n / 2;
		return 0;
	}else if(is1or0){
		if(m == 1)
		{
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{
				if(v[i] == 1)
				{
					ans++;
				}
			}
			cout << ans;
			return 0;
		}else if(m == 0){
			int ans = 0;
			for(int i = 1;i <= n;i++)
			{
				if(v[i] == 0)
				{
					ans++;
				}else if(i != n && v[i] == 1 && v[i+1] == 1){
					ans++;
					i++;
				}
			}
			cout << ans;
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int xorn = v[i];
		if(v[i] == m)
		{
			ans++;
			continue;
		}
		for(int j = i+1;j <= n;j++)
		{
			xorn ^= v[j];
			if(xorn == m)
			{
				ans++;
				i = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
