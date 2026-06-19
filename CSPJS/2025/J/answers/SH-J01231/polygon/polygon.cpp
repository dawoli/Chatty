#include <bits/stdc++.h>
using namespace std;
const int MOD = 988244353;
int n,a[5005];
long long cnt,maxn = -114514,sum;
long long c(int x,int y){
	int ans = 1;
	if(y > x/2) y = x-y;
	for(int i = x;i >= x-y+1;i--) ans *= i;
	for(int i = 1;i <= y;i++) ans /= i;
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]*1ll);	
		sum += a[i];
	}
	int ans = 0;
	if(n == 3){
		int sum = a[1]+a[2]+a[3];
		if(sum > 2*maxn) cout << 1;
		else cout << 0;
		return 0;
	}
	if(sum <= 2*maxn){
		cout << 0;
		return 0;
	}
	for(int i = 3;i <= n;i++){
		ans += c(n,i);
	}
	cout << ans;
	return 0;
}
