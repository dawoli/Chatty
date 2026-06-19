#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005],b[5005],ans,mx,mx_i,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx_i = (a[i] > mx ? i : mx_i);
		mx = (a[i] > mx ? a[i] : mx);
		b[i] = b[i-1]+a[i];
	}
	if (mx == 1){
		ans = 1;
		for (int i = 1;i <= n;i++) ans *= 2,ans %= mod;
		cout << ans;
		return 0;
	}
	else if(n == 3){
		cout << (b[3] / mx >= 2 ? 1 : 0);
		return 0;
	}
	else{
		ans = 1;
		for (int i = 1;i <= n;i++) ans *= 2,ans %= mod;
		cout << ans;
		return 0;	
	}
}
