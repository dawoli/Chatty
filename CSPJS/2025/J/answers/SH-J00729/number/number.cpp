#include<bits/stdc++.h>
using namespace std;
int b[20];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	for (int i = 0; i <= 9; ++i)
		b[i] = 0;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9){
			b[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; --i){
		if (b[i]){
			for (int j = 1; j <= b[i]; ++j)
				cout << i;
		}
	}
	return 0;
} 
