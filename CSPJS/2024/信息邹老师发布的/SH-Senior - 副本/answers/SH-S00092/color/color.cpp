#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , t , ans , a[200009];
void dfsBF(ll u , ll bl , ll rl , ll sum){
	if(u > n){
		ans = max(ans,sum);
		return;
	}
	if(a[bl] == a[u]) sum+=a[u];
	dfsBF(u+1,u,rl,sum);
	if(a[bl] == a[u]) sum-=a[u];
	if(a[rl] == a[u]) sum+=a[u];
	dfsBF(u+1,bl,u,sum);
	if(a[rl] == a[u]) sum-=a[u];
	return;
}
void solveBF(){
	ans = 0;
	dfsBF(1,0,0,0);
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(n < 20){
			solveBF(); 
		}
	}
	return 0;
} 
