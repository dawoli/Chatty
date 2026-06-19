#include <bits/stdc++.h>
using namespace std;

int t[100];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			t[s[i]-'0']++;
		}
	}
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= t[i]; j++){
			cout << i; 
		} 
	}
	cout << endl;
	return 0;
}
