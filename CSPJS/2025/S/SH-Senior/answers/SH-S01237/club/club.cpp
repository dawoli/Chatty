#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005][4],h[100005],t,maxn;
bool cmp(ll x,ll y){
	return x > y;
}
void solve(ll zz,ll cnt,ll l1,ll l2,ll l3){
	if(zz > n) {
		if(cnt > maxn){
			maxn = cnt; 
		}
	}
	if(l1 < n / 2){
		solve(zz + 1,cnt + a[zz][1],l1 + 1,l2,l3);
	}
	if(l2 < n / 2){
		solve(zz + 1,cnt + a[zz][2],l1,l2 + 1,l3);
	}
	if(l3 < n / 2){
		solve(zz + 1,cnt + a[zz][3],l1,l2,l3 + 1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool f = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] || a[i][3]){
				f = 1;
			}
		}
		if(!f){
			for(int i = 1;i <= n;i++){
				h[i] = a[i][1];
			}
			sort(h + 1,h + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++){
				maxn += h[i];
			} 
			cout << maxn <<'\n';
			maxn =0;
			continue;
		} 
		solve(0,0,0,0,0);
		cout << maxn << '\n';
		maxn = 0;
	}
	return 0;
} 
