#include<bits/stdc++.h>
using namespace std;
long long n, q, ans, cnt, period;
string s[200005][5], t[200005][5];
void check(string a, string b, string c, string d){
//	cout << "check : " << a << " " << b << " " << c << " " << d << endl; 
	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[0] && c[i] == d[0]){
			bool flag = true;
			for(int j = 0; j < b.size(); j++){
				if(a[i + j] != b[j] || c[i + j] != d[j]){
					flag = false;
					break;
				}
			}
			if(flag) ans++;
		}
	}
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q; 
	for(int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	for(int i = 1; i <= q; i++){
		cin >> t[i][1] >> t[i][2];
		cnt = period = 0;
		ans = 0;
		bool flag = true;
		for(int j = 0; j < t[i][1].size(); j++){
			if(t[i][1][j] == t[i][2][j]){
				if(cnt != 0) period++;
				continue;
			}
			else{
				if(period == 1){
					flag = false;
					break;
				}
				cnt++;
			}
		}
		if(!flag){
			cout << "0" << endl;
			continue;
		}
		if(q == 1){
			for(int j = 1; j <= n; j++){
				if(s[j][1].size() >= cnt && t[i][1].find(s[j][1]) == t[i][2].find(s[j][2])) ans++;
			}
		}
		else{
	//		cout << cnt << " " << period << endl;
			for(int j = 1; j <= n; j++){
				if(t[i][1].size() < s[j][1].size() || s[j][1].size() < cnt) continue;
				check(t[i][1], s[j][1], t[i][2], s[j][2]);
			}
		}
		cout << ans << endl;
	}
}
