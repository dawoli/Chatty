#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , r[100009] , ans , sum;
void solveBF(){
	sort(r+1,r+1+n);
	ll sum = 1;
	for(ll i = 2; i <= n; i++){
		if(r[i] == r[i-1]){
			sum += 1;
		}
		else{
			ans = max(ans,sum);
			sum = 1;
		}
	}
	ans = max(ans,sum);
	cout << ans;
	return;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> r[i];
	solveBF();
	return 0;
} 
