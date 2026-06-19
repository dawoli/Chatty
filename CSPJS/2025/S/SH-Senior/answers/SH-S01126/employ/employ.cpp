#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n,m;
char s[600];
int p[600];
int ans;
int a[600];
bool cnt[600];
int len;
bool judge() {
	int Give_up=0,num=0;
	for(int i = 1;i <= n;i++) {
		if(Give_up >= p[a[i]]) Give_up++;
		else {
			if(s[i]=='0') Give_up++;
			else num++;
		}
	}
	return num >= m;
}
void dfs(int pos) {
	if(pos == n+1) {
		ans += judge();
		return;
	}
	for(int i = 1;i <= n;i++) {
		if(!cnt[i]) {
			cnt[i]=1;
			a[++len]=i;
			dfs(pos+1);
			a[len--]=0;
			cnt[i]=0;
		}
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++) cin >> p[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
