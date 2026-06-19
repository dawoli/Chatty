#include <bits/stdc++.h>
using namespace std;
int p[506];
string s;
int n,m;
long long ans = 0;
long long mods = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i<=n;i++)cin>> p[i];
	if(n <= 18){
		vector<int> tp;
		for(int i = 1;i<=n;i++) tp.push_back(i);
		do{
			int outp = 0,okp = 0;
			for(int i = 0;i<n;i++){
				if(s[i] == '1' && outp < p[tp[i]]) okp++;
				else outp++;
			}
			if(okp >= m) ans =(ans+1)%mods;
		}while(next_permutation(tp.begin(),tp.end()));
		cout << ans;
		return 0;
	}
	bool fl = true;
	for(int i = 0;i<s.size();i++) if(s[i]!='1')fl = false;
	if(fl){
		int cntzero = 0;
		for(int i = 1;i<=n;i++) if(p[i] == 0) cntzero ++;
		if(m > n-cntzero) cout << 0;
		return 0;
	}
	int cntone = 0;
	for(int i = 0;i<n;i++) if(s[i] == 'a') cntone ++;
	if(cntone < m) {
		cout << 0;
		return 0; 
	}
	else if(m == n){
		int cntzero = 0;
		for(int i = 1;i<=n;i++) if(p[i] == 0) cntzero ++;
		if(cntzero > 0){
			cout << 0;
			return 0;
		} 
		cntzero = 0;
		for(int i = 1;i<=n;i++) if(s[i] == '0') cntzero ++;
		if(cntzero > 0){
			cout << 0;
			return 0;
		} 
		ans = 1;
		for(int i = 2;i<=n;i++) ans =ans*i%mods;
		cout << ans; 
		return 0;
	}
	
	return 0;
} 
