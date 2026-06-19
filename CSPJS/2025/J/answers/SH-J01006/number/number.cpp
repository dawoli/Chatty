#include <bits/stdc++.h>
using namespace std;

long long numbers[15];
char s[1000005];
char c;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i <= strlen(s) + 1; i++, c = s[i-1]){
		if (('0' <= c) && (c <= '9')){
			numbers[c-'0'] += 1;
		}
	}
	
	for(int i = 9; i >= 0; i--){
//		cout << numbers[i] << endl;
		for(int _ = 0; _ < numbers[i]; _++){
			cout << i;
		}
	}
	
	return 0;
}
