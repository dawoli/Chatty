#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n;
int a[5050];
int ans;
void dfs(int pos,int len,int sum,int mx) {
	if(pos == n+1) {
		if(sum>mx*2&&len>=3) {
			ans++;
			ans %= mod;
		}
		return;
	}
	dfs(pos+1,len+1,sum+a[pos],max(mx,a[pos]));
	dfs(pos+1,len,sum,mx);
}
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n<=20) {
		dfs(1,0,0,0);
		cout << ans << endl;
	}else {
		cout << "Smile ^_^" << endl;
		cout << "Next year will be the last" << endl;
		cout << "Hope to have J1= in this year" << endl;
		cout << "Already been 2= for 2 years" << endl;
		cout << "Expect:100+100+100+40=340" << endl;
		cout << "Problems are simple" << endl;
		cout << "Wish no bugs in T1,T2,T3" << endl;
		cout << "Bye." << endl;
	}
	return 0;
}
