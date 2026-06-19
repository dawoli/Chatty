#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200005][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	for(int i = 0;i < n;i++)
		cin >> s[i][0] >> s[i][1];
	while(q--){
		string t1,t2;
		cin >> t1 >> t2;
		int ans = 0;
		for(int i = 0;i < n;i++){
			int k = 0;
			bool f = false;
			int l;
			for(int j = 0;j < t1.size();j++){
				if(t1[j] != s[i][0][k]) k = 0;
				if(t1[j] == s[i][0][k]) k++;
				if(k == s[i][0].size()) {
					f = true;
					l = j;
				}
			}
			if(f){
				string t3 = "";
				for(int j = 1;j <= l-k;j++){
					t3 += t1[j-1];
				}
				t3 += s[i][1];
				for(int j = l;j < t1.size();j++){
					t3 += t1[j];
				}
				if(t3 == t2) ans++;
			}
		}
		cout << ans << "\n"; 
	} 
}
