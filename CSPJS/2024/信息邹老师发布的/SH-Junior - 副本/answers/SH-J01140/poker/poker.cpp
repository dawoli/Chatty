#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int n, c;
string p;
map<string, bool> m;
map<string, bool>::iterator k;

int main(){
	freopen("poker.in", "r", stdin), freopen("poker.out", "w", stdout), cin >> n;
	for (int i = 1; i <= n; i++) cin >> p, m[p] = 1;
	for (k = m.begin(); k != m.end(); k++) if (k->second) c++;
	cout << 52 - c << "\n";
	return 0;
}
