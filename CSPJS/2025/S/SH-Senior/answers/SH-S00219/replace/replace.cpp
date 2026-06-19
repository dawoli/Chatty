#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n,q,f[2000010],d[2000010],a[2000010];string s[200010],t[200010],x,y;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i] >> t[i];
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		if(x.size() != y.size()){
			cout << "0\n";
			continue;
		}
		int l = x.size(),r = -1;
		for(int j = 0;j < x.size();j++){
			if(x[j] != y[j]){
				r = j;
				if(l == x.size()) l = j;
			}
		}
		int ans = 0;
		for(int j = 1;j <= n;j++){
			string u = s[j] + "#" + x,v = t[j] + "#" + y;
			int cnt = 0;
			for(int k = 1;k < u.size();k++){
				int p = f[k - 1];
				while(u[p] != u[k] && p) p = f[p - 1];
				if(u[p] == u[k]) p++;
				f[k] = p;
				if(p == s[j].size()) a[++cnt] = k;
			}
			int c = 0;
			for(int k = 1;k < v.size();k++){
				int p = d[k - 1];
				while(v[p] != v[k] && p) p = d[p - 1];
				if(v[p] == v[k]) p++;
				d[k] = p;
				if(p != t[j].size()) continue;
				while(a[c] < k && c < cnt) c++;
				if(a[c] == k && r < k - s[j].size() && l >= k - 2 * s[j].size()){
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
