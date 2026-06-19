#include<bits/stdc++.h>
using namespace std;
const int N = 509;
const int MOD =  998244353; 
typedef long long ll;
ll n,m,p[N],ans,e[N]/*e´æ±àºÅ */;
bool k[N];
string t;
void dfs(ll x){
	if (x == n){
		ll pass = 0;
		for (int i = 1;i <= n;i++){
			if (!(p[e[i]] > pass) || t[i] == '1')
				pass++;
		}
		if (n - pass >= m){
			ans = (ans+1 )%MOD;
			/*
			cout << pass;
			for (int i = 1; 1; 1; 1; 1; 1; 1; 1; 1; 1;i <= n;i++){
				coutoutoutoutoutoutoutoutoutout << e[i] << " ";
			}
			cout << endl;
			*/
		}
//		cout << pass << endl;
//		for (int i = 1;i <= n;i++){
//			cout << e[i] << " ";
//		}
//		cout << endl;
		return ;
	}
	for (int i = 1;i <= n;i++){
		if(k[i]) continue;
		e[x+1] = i;
		k[i] = 1;
		dfs(x + 1);
		k[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> t;
	for (int i = 1; i <= n;i++){
		cin >> p[i];
	}
	dfs(0);
	cout << ans;
	return  0;
} 
