//一重循环，字符和ASCII关系
#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	int sum = 0;
	for (int i=0;i<str.length();i++) {
		char ch=str[i];
		if (ch >= 'a' && ch <= 'z') {
			sum += (int)ch - 96;
		} else {
			sum -= (int)ch;
		}
	}
	cout << sum << endl;
	return 0;
}
