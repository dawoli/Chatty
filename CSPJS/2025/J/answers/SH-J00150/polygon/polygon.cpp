#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	vector<int> a(n+1);
	for (int i=1;i<=n;i++){
		cin >> a[i];
	} 
	for (int i=1;i<(1<<n);i++){
		int sum = 0,maxx = -1,cnt = 0;
		for (int j=0;(1<<j)<=i;j++){
			//cout << (i>>j&1) << ' ';
			if (i>>j&1){
				sum += a[j+1];
				cnt++;
				maxx = max(maxx,a[j+1]);
			}
		}
		if (sum>maxx*2 && cnt>=3){
			ans++;
			ans %= MOD;
		}
		//cout << '\n';
	}
	cout << ans;
	return 0;
}
