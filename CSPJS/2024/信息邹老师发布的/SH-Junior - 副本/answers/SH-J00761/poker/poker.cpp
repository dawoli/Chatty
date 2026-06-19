// poker.cpp
#include <iostream>
#include <string>
#include <set>
#include <cstdio>
using namespace std;
int n;
// poke: P's own poke
set<string> poke;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	// query
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		//processing
		po ke.insert(str);
	}
	// output
	cout << 52 - poke.size();
	return 0;
}
