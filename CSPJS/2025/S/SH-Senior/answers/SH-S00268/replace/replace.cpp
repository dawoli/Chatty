#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

string s[200005][3];

int main(){
#ifndef DEBUG
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string a, b;
		cin >> a >> b;
		int st = 0, ed = a.size() - 1;
		for(int j = 0; j < a.size(); j++){
			if(a[j] == b[j]){
				st++;
			}else{
				break;
			}
		}
		for(int j = a.size() - 1; j >= 0; j--){
			if(a[j] == b[j]){
				ed--;
			}else{
				break;
			}
		}
		string nxta, nxtb;
		for(int j = st; j <= ed; j++){
			nxta += a[j], nxtb += b[j];
		}
		s[i][1] = nxta;
		s[i][2] = nxtb;
#ifdef DEBUG
		cout << "Proceed str " << i << "-1: " << s[i][1] << endl
			 << "Proceed str " << i << "-2: " << s[i][2] << endl;
#endif
	}
	for(int i = 1; i <= q; i++){
		string a, b;
		cin >> a >> b;
		if(a == b){
			cout << n << endl;
			continue;
		}
		int st = 0, ed = a.size() - 1;
		for(int j = 0; j < a.size(); j++){
			if(a[j] == b[j]){
				st++;
			}else{
				break;
			}
		}
		for(int j = a.size() - 1; j >= 0; j--){
			if(a[j] == b[j]){
				ed--;
			}else{
				break;
			}
		}
		string nxta, nxtb;
		for(int j = st; j <= ed; j++){
			nxta += a[j], nxtb += b[j];
		}
#ifdef DEBUG
		cout << "Proceed str " << i << "-1: " << nxta << endl
			 << "Proceed str " << i << "-2: " << nxtb << endl;
#endif
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(s[i][1] == nxta && s[i][2] == nxtb){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
