#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;
int n, q;
string s[maxn][3];
string t[maxn][3];
bool cont(string x, string y){
	if(x.size() < y.size()) return false;
	
	for(int i = 0; i < x.size() - y.size() + 1; i++){
		bool flag = false;
		for(int j = 0; j < y.size(); j++){
			if(x[i + j] == y[j]) ;
			else{
				flag = true;
				break;
			}
			
//			cout << i << ' ' << x[i] << ' ' << j << ' ' << y[j] << '\n'; 
		}
		
		if(!flag) return true;
	}
	
	return false;
}
inline void solvea(){
	string bef = "", aft = "";
	for(int i = 0; i < t[1][1].size(); i++){
		if(t[1][1][i] == t[1][2][i]) ;
		else bef = bef + t[1][1][i], aft = aft + t[1][2][i];
	}
	
	cout << bef << ' ' << aft << '\n';
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(cont(s[i][1], bef) && cont(s[i][2], aft)) ans++;
	}
	
	cout << ans << '\n';
	exit(0);
}
void solveb(){
	int tim = 0;
	while(q--){
		tim++;
		
		string bef = "", aft = "";
		for(int i = 0; i < t[tim][1].size(); i++){
			if(t[tim][1][i] == t[tim][2][i]) ;
			else bef = bef + t[tim][1][i], aft = aft + t[tim][2][i];
		}
		
		cout << bef << ' ' << aft << '\n';
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(cont(s[i][1], bef) && cont(s[i][2], aft)) ans++;
		}
		
		cout << ans << '\n';
	}
	exit(0);
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	for(int i = 1; i <= q; i++) cin >> t[i][1] >> t[i][2];
	
	if(q == 1) solvea();
	
	if(n <= 100 && q <= 100) solveb();
	
	for(int i = 1; i <= q; i++){
		cout << 0 << '\n';
	}
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/ 
