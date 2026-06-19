#include <bits/stdc++.h>
using namespace std;
string s[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n; cin >> n ;
	int m = 52;
	for(int i = 1; i <= n; ++ i){
		cin >> s[i];
		for(int j = 1; j < i; ++ j){
			if(s[i] == s[j]) {
				m++;break;
			}
		}
		-- m;
	}
	cout << m;
} 
