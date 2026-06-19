#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
string s[N], to[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i ++){
		cin >> s[i] >> to[i];
	}
	string t1, t2; int ans = 0;
	for (int i = 1; i <= q; i ++){
		ans = 0; cin >> t1 >> t2;
		
		for (int i = 1; i <= n; i ++){
			for (int t = 0; t + s[i].length() <= t1.length(); t ++){
				//cout << t1.substr(t, s[i].length()) << ' ' << t2.substr(t, s[i].length()) << ' ';
				if (t1.substr(t, s[i].length()) == s[i]){
					if (t2.substr(t, s[i].length()) == to[i]){
						for (int qqq = t + s[i].length(); qqq < t1.length(); qqq ++){
							if (t1[qqq] != t2[qqq]){
								//cout << "NO!\n";
								goto no;
							}
						}
						++ans; //cout <<"RIGHT!\n";
						no:
						break;
					}//else cout << "NO!\n";
				}//else cout << "NO!\n";
			}
		}
		cout <<ans << '\n';
	}
}
