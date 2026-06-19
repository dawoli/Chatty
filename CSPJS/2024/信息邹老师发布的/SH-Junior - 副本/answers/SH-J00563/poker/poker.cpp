#include <bits/stdc++.h>
using namespace std;
int n;
set <string> s;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	string k;
	for (int i = 1; i <= n; i++){
		cin >> k;
		s.insert(k);
	}cout << 52 - s.size() << endl;
	return 0;
} 
