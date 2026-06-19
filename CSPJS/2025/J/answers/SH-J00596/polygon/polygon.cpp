#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 998244353;
const int N = 5010;
ll arr[N];
ll prf[N];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ll num = 0;
	ll mx = 0;
	cin>>num;
	for(int ini = 1; ini <= num; ini++)
	{
		cin>>arr[ini];
		prf[ini] = prf[ini-1] + arr[ini];
		mx = max(arr[ini], mx);
	}
	if(num < 3)
	{
		cout<<0;
		return 0;
	}
	if(num == 3)
	{
		if(prf[num] > 2*mx)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	return 0;
 } 
