#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > rep;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	scanf("%d%d",&n,&q);
	rep.assign(n + 1, vector<string>());
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < 2;j++) {
			string s;
			cin >> s;
			rep[i].push_back(s);
		}
	}
	while(q--) {
		string a, b;
		cin >> a >> b;
		ll ans = 0;
		int l = a.length();
		for(int i = 0;i < n;i++) {
			string t = a;
			int cnt = 0,st = 0;
			string k = rep[i][0];
			string o = rep[i][1];
			for(int i = 0;i < l;i++) {
				if(cnt == k.length()) break;
				if(t[i] == k[0] && cnt == 0) {
					cnt++;
					st = i;
					continue;
				}
				if(cnt > 0) {
					if(t[i] == k[cnt]) {
						cnt++;
					}
					else cnt = 0;
				}
				
			}
			if(cnt == k.length()) {
				for(int j = 0;j < cnt;j++) {
					t[st + j] = o[j];
				}
			}
			if(t == b) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
