#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s[100];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	cout << 52 - n;
	return 0;
}
