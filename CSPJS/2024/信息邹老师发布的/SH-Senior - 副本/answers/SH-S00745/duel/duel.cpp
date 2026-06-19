#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 6;

// 记得开long long 
// 记得检查文件读入读出 
ll a[N]; 
bool vis[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	ll n; cin >> n;
	for(ll i=1; i<=n; i++) cin >> a[i];
	
	sort(a+1, a+1+n);
	
	ll cnt = 0;
	for(ll i=1; i<=n; i++)
	{
		ll l = i, r = n+1;
		while(l+1 != r)
		{
			ll mid = l+r >> 1;
			if(a[mid] > a[i]) r = mid;
			else l = mid;
		}
		while(vis[r] && r<=n) r++;
		if(r <= n)
		{
			vis[r] = 1;
			cnt ++;
		}
		
	}
	
	cout << n - cnt;
	
	return 0;	
}
