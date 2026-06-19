#include <bits/stdc++.h>
using namespace std;

string s;
int n, m, lim;
int c[505];
bool spe = 1;
int reall;
long long f(int n){
	long long res = 1;
	for(int i = 2; i <= n; i++){
		res *= i;
		res %= 998244353;
	}
	return res;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] > lim){
			reall++;
		}else{
			lim++;
		}
	}
	for(int i = 0; i < s.length(); i++){
		if(s[i] - '0' != 1){
			spe = 0;
		}
	}
	if(spe){
		cout << f(reall);
		return 0;
	}
	cout << 0;
	return 0;
}
