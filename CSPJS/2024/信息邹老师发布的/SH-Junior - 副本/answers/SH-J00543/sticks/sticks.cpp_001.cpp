#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n, dig = 0;
int a[10] = {6, 2, 5, 4, 6, 3, 7};
int f[10] = {0, 1, 2, 4, 6, 7, 8};
void dfs(ll stk, ll stp, ll now){
	if(now > stp) return ;
	else if(now == 1){
		for(int i = 1; i <= 6; ++i){
			if((stk - a[i]) > 7 * (stp - now)) continue;
			else{
				stk -= a[i];
				cout << f[i];
				break;
			}
		}
		dfs(stk, stp, now + 1);
	}
	else{
		for(int i = 0; i <= 6; ++i){
			if((stk - a[i]) > 7 * (stp - now)) continue;
			else{
				stk -= a[i];
				cout << f[i];
				break;
			}
		}
		dfs(stk, stp, now + 1);
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		if(n < 2) cout << -1 << "\n";
		else if(n == 2) cout << 1 << "\n";
		else if(n == 3) cout << 7 << "\n";
		else if(n == 4) cout << 4 << "\n";
		else if(n == 5) cout << 2 << "\n";
		else if(n == 6) cout << 6 << "\n";
		else if(n % 7 == 0){
			for(ll i = 1; i <= n / 7; ++i)
				cout << 8;
			cout << "\n";
		}
		else if(n % 7 == 1){
			cout << 10;
			for(ll i = 1; i <= n / 7 - 1; ++i)
				cout << 8;
			cout << "\n";
		}
		else{
			dig = n / 7 + 1;
			dfs(n, dig, 1);
			cout << "\n";
		}
	}
	return 0;
}
