#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[500005];
ll xor_arr[500005];
vector<pair<ll, ll> > v;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ll n, k;
	cin >> n >>k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >>arr[i];
		if (arr[i] == k) v.push_back({i, i});
	}
	xor_arr[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		xor_arr[i] = xor_arr[i - 1] ^ arr[i];
		if (xor_arr[i] == k)
		{
			v.push_back({0, i});
		}
		for (int j = 1; j < i; j++)
		{
			if ((xor_arr[i] ^ xor_arr[j]) == k)
			{
				v.push_back({j + 1, i});
			}
		}
	}
	sort(v.begin(), v.end());
	
	ll cnt = 0;
	ll last_pos = 1000000005;
	
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i].second < last_pos)
		{
			cnt++;
			last_pos = v[i].first;
		}
	}
	
	cout << cnt <<endl;
	
	return 0;
} 
