#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;

const ll mod = 998244353,maxn = 505;
ll n,m,c[maxn],ans;
bool vis[maxn],flag = 1;
string s,test;
void input(){
	cin >> n >> m >> s;
	for(auto i : s){
		if(i == '0') flag = 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
}
void dfs(ll k,vector<ll> &a){
	if(k == n + 1){
		ll sum = 0,cnt = 0;
		for(int i = 0;i < n;i++){
			if(a[i] < cnt) cnt++;
			else sum += (s[i] - '0');
		}
		if(sum >= m){
			ans = (ans + 1) % mod;
		}
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			a.push_back(c[i]);
			vis[i] = 1;
			dfs(k + 1,a);
			a.pop_back();
			vis[i] = 0;
		}
	}
}
ll js(ll x){
	ll res = 1;
	for(ll i = 2;i <= x;i++) res = (res * i) % mod;
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	input();
	if(flag) cout << js(n);
	vector<ll> a;
	dfs(1,a);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
