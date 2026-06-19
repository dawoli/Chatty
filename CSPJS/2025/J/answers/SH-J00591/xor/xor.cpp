#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll sum[500010];
struct node{
	ll l,r;
}Joanne[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	ll dir = 0;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		if(i > 1) sum[i] = sum[i - 1] ^ a[i];
		else sum[i] = a[i];
	}
	for(ll j = 1;j <= n;j++){
		if(sum[j] == m){
			Joanne[++dir].l = 1;
			Joanne[dir].r = j;
		}
	}
	for(ll i = 2;i <= n;i++){
		for(ll j = i;j <= n;j++){
			if((sum[j] ^ sum[i - 1]) == m){
				Joanne[++dir].l = i;
				Joanne[dir].r = j;
			}
		}
	}
	ll cnt = 1;
	ll lastl = Joanne[1].l;
	ll lastr = Joanne[1].r;
	for(ll i = 1;i <= dir - 1;i++){
		if(lastr < Joanne[i + 1].l){
			cnt++;
			lastl = Joanne[i + 1].l;
			lastr = Joanne[i + 1].r;
		}
	}
	cout << cnt << endl;
	return 0;
}
