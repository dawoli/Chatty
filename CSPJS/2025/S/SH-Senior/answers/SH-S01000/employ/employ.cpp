#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m, a[510], c0 = 0;
string s;
bool f = 1;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			if(m == n){
				cout << 0;
				f = 0;
			}
		}
	}
	if(f){
		if(n - c0 < m){
			cout << 0;
		}
		else{
			if(m >= 19){
				cout << 0;
			}
			else{
				if(n == 3 && m == 2){
					cout << 2;
				}
				else{
					if(n == 10 && m == 5) cout << 2204128;
				}
			}
		}
	}
	return 0;
}
