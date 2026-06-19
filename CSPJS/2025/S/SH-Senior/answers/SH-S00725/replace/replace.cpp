#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, q;
map <string, string> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		string s1, s2;
		cin >> s1 >> s2;
		mp.insert({s1, s2});
	}
	while(q--){
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 0; i < s1.length(); ++i){
			for (int j = 1; j <= s1.length() - i; ++j){
				string temp = s1.substr(i, j);
				if (mp.find(temp) != mp.end()){
					string s3;
					if (i != 0)
						s3 = s1.substr(0, i);
					s3 = s3 + mp[temp];
					if (i + j != s1.length())
						s3 = s3 + s1.substr(i + j, s1.length() - (i + j));
					if (s3 == s2)
						++ans; 
				}
			}
		}
		cout << ans << "\n";
	}
	return 0; 
}
