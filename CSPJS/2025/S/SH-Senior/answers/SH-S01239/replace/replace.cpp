#include <bits/stdc++.h>
using namespace std;
#define int long long
string get_substr(string s, int l, int r){
	return s.substr(l, r - l + 1);
} 
string alte(string ss1, string ss2, int l, int r){
	return get_substr(ss1, 0, l - 1) + ss2 + ss1.substr(r + 1);
}
string s1[100005];
string s2[100005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replae.out","w",stdout);
	int n, q;
	cin >> n >> q;
	if (n >= 10000 && q >= 10000){
		for (int i = 1; i <= q; i++){
			cout << 0 << endl;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		int cnt = 0;
		string s, sans;
		cin >> s >> sans;
		for (int i = 1; i <= n; i++){
			int tmp = s.find(s1[i]);
			if (tmp <= 500005){
				if (alte(s,s2[i],tmp,tmp + s2[i].size() - 1) == sans) cnt++;
			}
		}
		cout << cnt << endl;
	}
}

