#include <bits/stdc++.h>
using namespace std;
bool flag=true;
long long n, a[5005], p[5005], ans, mod=998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(n==3){
		int maxn=max(a[1], max(a[2], a[3]));
		if(a[1]+a[2]+a[3]>maxn){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	if(flag){
		int ans=2;
		for(int i=n-1; i>=3; i--){
			ans+=i*(i-1)/2;
			ans=ans%mod;
		}
		cout << ans%mod;
		
		return 0;
	}
	
	
	
	return 0;
}
