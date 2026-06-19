#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int c[505];
int ans=0;
string s;
bool ch[505];
void dfs(int dep,int h) {
	if(dep==n) {
		if(h>=m) {
			ans++;
			if(ans==3) {
				cout << h << endl;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++) {
		if(ch[i]==0) {
			ch[i]=1;
			if(dep-h>=c[i]||s[i]=='0') {
				dfs(dep+1,h);
			}
			else {
				dfs(dep+1,h+1);
			}
			ch[i]=0;
		}
	}
	return;
}
signed main() {
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s="a"+s;
	for(int i=1;i<=n;i++) cin >> c[i];
	dfs(0,0);
	cout << ans << endl;
	return 0;
} 
