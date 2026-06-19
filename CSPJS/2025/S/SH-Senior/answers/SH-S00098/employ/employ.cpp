#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m , c[509] , sum , a[509] , p[509] , dp[509] , ok[509];
string s;
void dfs(ll id,ll cnt){
	if(id > n){
		if(cnt + m <= n){
			//cout<<cnt<<endl;
			sum = (sum + 1) % 998244353;
			//for(ll i = 1; i <= n; i++) cout << dp[i] << " ";
			//cout << endl;
		} 
		return;
	}
	if(cnt + m > n) return;
	for(ll i = 1; i <= n; i++){
		if(ok[i] == 1) continue;
		ok[i] = 1;
		dp[id] = i;
		if(a[i] <= cnt){
			cnt++;
			dfs(id+1,cnt);
			cnt--;
		}
		else if(s[id-1] == '0'){
			cnt++;
			dfs(id+1,cnt);
			cnt--;
		}
		else{
			dfs(id+1,cnt);
		}
		ok[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(ll i = 1 ; i <= n; i++){
		cin >> a[i];
	}
	dfs(1,0);
	cout << sum << endl;
	return 0;
} 
