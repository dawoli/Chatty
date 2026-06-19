#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5010],pre[5010],cnt;
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	ll sum = 0,mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
		mx = max(mx,a[i]);
	}
	if(n == 3){
		if(sum > mx * 2) cout << 1;
		else cout << 0;
	}else{
		ll sum = 0;
		ll x = 1;
		for(int j = 1;j <= n;j++){
			x *= j % 998244353;
		}
		for(int i = 3;i <= n;i++){
			ll y = 1,z = 1;
			for(int j = 1;j <= i;j++){
				y *= j % 998244353;
			}
			for(int j = 1;j <= n - i;j++){
				z *= j % 998244353;
			}
			sum += x / (y * z) % 998244353;
		//cout << x <<" " << y << " " << z << endl;
		}
		cout << sum % 998244353;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
