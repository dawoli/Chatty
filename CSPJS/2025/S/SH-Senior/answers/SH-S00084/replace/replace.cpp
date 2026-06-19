#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
int n,q,ans;
string s[2005][2],a,b;
map <string,bool> mp,mp1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
		mp[s[i][0]] = 1;
	}
	for(int i = 1;i <= q;i++){
		cin >> a >> b;
		ans = 0;
		if(a.size() != b.size()){
			cout << "0\n";
			continue;
		}
		int l = 0,r = 0,j = 0;
		bool flag = 0,flag1 = 0;
		string k = "";
		while(j < a.size()){
			if(a[j] != b[j]){
				if(l == 0){
					l = j;r = j;
					while(r + 1 < a.size() && a[j + 1] != b[j + 1]){
						r++;
						j++;
					}
					j += 1;
				}
				else {
					r = j;
					while(r + 1 < a.size() && a[j + 1] != b[j + 1]){
						r++;
						j++;
					}
					j += 1;
				}
			}
			else j++;
		}
		for(int pl = l;pl <= r;pl++)
			k += a[pl];
		for(int pl = l;pl >= 0;pl--){
			if(pl != l) k = a[pl] + k;
			string e = k;
			ans += mp[k];
			for(int pr = r + 1;pr < a.size();pr++){
				k += a[pr];
				ans += mp[k];
			}
			k = e;
		}
		cout << ans << "\n";
	}
	return 0;
}
