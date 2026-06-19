#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
struct Key {
	string s,t;
}a[200200];
map<pair<string,string>,bool> mp;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].s >> a[i].t;
		mp[{a[i].s,a[i].t}]=1;
	}
	while(q--) {
		string x,y;
		cin >> x >> y;
		if(x.length()!=y.length()) {
			cout << 0 << endl;
			continue;
		}
		int ans=0;
		for(int i = 0;i < x.length();i++) {
			for(int j = i;j < x.length();j++) {
				string A1 = x.substr(0,i);
				string A2 = y.substr(0,i);
				string X1 = x.substr(i,j-i+1);
				string X2 = y.substr(i,j-i+1);
				string B1 = x.substr(j+1);
				string B2 = y.substr(j+1);
				if(A1==A2&&B1==B2&&mp[{X1,X2}]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
