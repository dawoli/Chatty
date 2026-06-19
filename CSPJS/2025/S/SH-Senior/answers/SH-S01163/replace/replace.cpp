#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
ll n, q, ans, pre[N];
string s1[N], s2[N], t1[N], t2[N], p1, p2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		ll j = 0, k = 0;
		while(j < s1[i].size() && k < s2[i].size() && s1[i][j] == s2[i][k]){
			j++;
			k++;
		}
		pre[i] = j;
	}
	for(ll i = 1; i <= q; i++){
		cin >> t1[i] >> t2[i];
		ans = 0;
		for(ll j = 1; j <= n; j++){
			p1 = t1[i];
			p2 = t2[i];
			bool flag = 0, ok = 1;
			for(ll k = 0; k < p2.size(); k++){
				if(k >= p1.size()){
					ok = 0;
					break;
				}
				if(p1[k] != p2[k]){
					if(flag){
						ok = 0;
						break;
					}
					ll l = pre[j];
					for(ll t = 0; t < l; t++){
						if(s1[j][t] != p1[k - l + t] || s2[j][t] != p2[k - l + t]){
							ok = 0;
							break;
						}
					}
					if(!ok) break;
					while(k < min(p1.size(), p2.size()) && l < min(s1[j].size(), s2[j].size()) && p1[k] == s1[j][l] && p2[k] == s2[j][l]){
						p1[k] = s2[j][l];
						k++;
						l++;
					}
					if(l < min(s1[j].size(), s2[j].size())){
						ok = 0;
						break;
					}else{
						if(s1[j].size() < s2[j].size()){
							while(k < p2.size() && l < s2[j].size() && p2[k] == s2[j][l]){
								l++;
								k++;
								p1 = " " + p1;
							}
							if(l < s2[j].size()){
								ok = 0;
								break;
							}
						}else if(s1[j].size() < s2[j].size()){
							while(k < p1.size() && l < s1[j].size() && p1[k] == s1[j][l]){
								l++;
								k++;
								p2 = " " + p2;
							}
							if(l < s1[j].size()){
								ok = 0;
								break;
							}
						}else{
						}
					}
					flag = 1;
					k--;
				}
			}
			if(ok && p2.size() == p1.size()) ans++;
		}
		cout << ans << endl;
	}
	return 0;
} 
