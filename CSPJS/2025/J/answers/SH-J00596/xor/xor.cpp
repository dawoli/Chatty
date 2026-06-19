#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5+10;
ll arr[N];
ll tmp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll num = 0, ans = 0, anse = 0;
	cin>>num>>ans;
	for(int ini = 1; ini <= num; ini++)
	{
		cin>>arr[ini];
		tmp = tmp ^ arr[ini];
		if(tmp == ans)
		{
			anse++;
			tmp = 0;
		}
	}
	cout<<anse;
	return 0;
}
