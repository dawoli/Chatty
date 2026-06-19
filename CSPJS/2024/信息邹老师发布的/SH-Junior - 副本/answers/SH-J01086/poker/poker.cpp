#include <bits/stdc++.h>
using namespace std;
map <char, int> value;
int main () {
	value ['S'] = 0;
	value ['H'] = 1;
	value ['C'] = 2;
	value ['D'] = 3;
	value ['A'] = 1;
	value ['2'] = 2;
	value ['3'] = 3;
	value ['4'] = 4;
	value ['5'] = 5;
	value ['6'] = 6;
	value ['7'] = 7;
	value ['8'] = 8;
	value ['9'] = 9;
	value ['T'] = 10;
	value ['J'] = 11;
	value ['Q'] = 12;
	value ['K'] = 13;
	freopen ("poker.in", "r", stdin);
	freopen ("poker.out", "w", stdout);
	int n, cnt [60];
	memset (cnt, 0, sizeof (cnt));
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		string k;
		cin >> k; 
		cnt [value [k [0]] * 13 + value [k [1]]] ++;
	}
	int sum = 0;
	for (int i = 1; i <= 52; i ++) {
		if (cnt [i] == 0) sum ++;
	}
	cout << sum;
}