#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, cnt;
map<string, bool> m;
char a, c;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	while (n--) {
		cin >> a >> c;
		string s = " ";
		s += a + c;
		if (!m[s]){
			m[s] = 1;
			cnt++;
		}
	}
	cout << 52 - cnt;
	return 0;
} 
