#include <iostream>
#include <algorithm>
using namespace std;
string s, str;
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (auto ch : s)
		if (ch >= '0' && ch <= '9')
			str.push_back(ch);
	sort(str.begin(), str.end(), cmp);
	cout << str;
	return 0;
}
