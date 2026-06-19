#include<iostream>
using namespace std;

string s;
int a[500] = {0};

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(unsigned int i = 0; i < s.length(); i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[s[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < a[i]; j++){
			cout << i;
		}
	}
	
	return 0;
}
