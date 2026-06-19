#include <iostream>
#include <vector>
#include <map>
using namespace std;

int ss[5000005];
string s1[200005], s2[200005];
int nxt[5000005];
map<int, bool> mp;
void build_nxt(string s){
	nxt[0] = 0;
	int l = 0;
	for (int i = 1; i < s.size(); i++){
		if (s[i] == s[l]){
			nxt[i] = l + 1;
			l++;
		} else {
			while (s[i] != s[l] && l != 0) l = nxt[l-1];
			nxt[i] = l;
		}
	}
} 
int kmp(bool type, string a, string b){
	if (a.size() < b.size()) return 0;
	build_nxt(b);
	int re = 0;
	int l = 0;
	for (int i = 0; i <= a.size(); i++){
		if (a[i] == b[l]){
			l++;
			if (l >= b.size()){
				if (type) mp[i] = true;
				else if (mp.count(i) && (i < b.size() || ss[i - b.size()] == 0) && ss[a.size()-1] == ss[i]) re++;
				l = nxt[l-1];
			}
		} else {
			while (a[i] != b[l] && l != 0) l = nxt[l-1];
			if (a[i] == b[l]) l++;
		}
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s1[i] >> s2[i];
	while (q--){
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size()){
			cout << 0 << '\n';
			continue;
		}
		for (int i = 0; i < a.size(); i++)
			ss[i] = ss[i-1] + (a[i] != b[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++){
			mp.clear();
			kmp(1, a, s1[i]);
			ans += kmp(0, b, s2[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
