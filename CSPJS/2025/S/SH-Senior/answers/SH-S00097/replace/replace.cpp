#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
map<string, string> mp;
string s[MAXN];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	cin >> n >> q;
	for(long long i = 1; i <= n; i++){
		string a, b;
		cin >> a >> b;
		mp[a] = b;
		s[i] = a;
	}
	for(long long i = 1; i <= q; i++){
		long long ans = 0;
		string a, b;
		cin >> a >> b;
		for(long long j = 1; j <= n; j++){
			long long k = a.find(s[j]);
			if(k < a.size()){
				string temp = a.substr(0, k - 0) + mp[s[j]] + a.substr(k + s[j].size(), a.size() - k - s[j].size());
				if(temp == b){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
