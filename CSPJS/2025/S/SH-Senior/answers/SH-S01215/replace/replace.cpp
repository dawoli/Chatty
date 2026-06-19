#include <bits/stdc++.h>
using namespace std;
int n=0,q=0,ans=0;
string s[5000010][2];
void find(string t1,string t2){
	if(t1.size() != t2.size()) return;
	string t;
	for(int i = 0;i < t1.size();i++){
		for(int j = 0;j < n;j++){
			bool bol=0;
			t = t1;
			int ii = i;
			for(int k = 0;k < s[j][0].size();k++){
				if(t[ii] == s[j][0][k] && t2[ii] == s[j][1][k]){
					t[ii] = t2[ii];
				}else{
					bol = 1;
					break; 
				}
				ii++;
			}
			if(bol){
				continue;
			}else if(t == t2){
				ans++;
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i = 0;i < q;i++){
		string t1,t2;
		ans=0;
		cin >> t1 >> t2;
		find(t1,t2);
		cout << ans;
	}
	return 0;
}
