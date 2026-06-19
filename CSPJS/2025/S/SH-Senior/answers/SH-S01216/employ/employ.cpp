#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll M = 1009;
ll n, m;
bool s[M];
ll c[M];
ll p[M];
ll cnt = 0;
void solveBF10(){
	for(ll i = 1;i<=n;i++){
		p[i] = i;
	}
	do{
		ll reject = 0, accept = 0;
		for(ll i = 1;i<=n;i++){
			if(reject<c[p[i]] && s[i]){
				accept++;
			}else{
				reject++; 
			} 
		}
		if(accept>=m){
			cnt = (cnt+1) % MOD;
		} 
		
		
	}while(next_permutation(p+1, p+1+n));
	cout<<cnt<<"\n";
}
void solvemn(){
	//cout<<"solvemn:\n";
	for(ll i = 1;i<=n;i++){
		if(s[i]==0 || c[i]==0){
			cout<<"0\n";
			return;
		}
	}
	
	ll mul = 1;
	for(ll i = 1;i<=n;i++){
		mul = (mul * i) % MOD; 
	}
	cout<<mul<<"\n";
}
ll mul[M];
void prework(){
	mul[1] = 1;
	for(ll i = 2;i<=500;i++){
		mul[i] = mul[i-1] * i % MOD;
	}
}
//void solve_all1(){
//	sort(c+1, c+1+n);
//	ll all = 1;
//	for(ll i = 1;i<=n;i++){
//		all = (all * i) % MOD;
//	}
//	ll remove = 1;
//	ll sub = 1;
//	for(ll i = 1;i<=n-m || (i==n-m && s[i]==s[i+1]) || s[i]==s[i-1];i++){
//		if(s[i] > i){
//			cout<<all<"\n";
//			return;
//		}
//		if(i>1 && s[i]==s[i-1]){
//			sub++;
//		}else{
//			remove = (remove * mul[sub]) % MOD;
//			sub = 1;
//		}
//	}
//	
//	remove = (remove * mul[n-m]) % MOD;
//	all = (all + MOD - remove) % MOD;
//	cout<<all<<"\n"; 
//} 
ll onecnt = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//cout<<(1<<18)<<"\n";
	cin >> n >> m; 
	for(ll i = 1;i<=n;i++){
		char ch;
		cin >> ch;
		if(ch=='0') s[i] = 0;
		else{
			onecnt++;
			s[i] = 1;
		}
	}
	for(ll i = 1;i<=n;i++){
		cin >> c[i]; 
	}
	
	if(n<=10){
		solveBF10();
		return 0;
	}
	if(m==n){
		solvemn();
		return 0;
	}

	
	return 0;
}
