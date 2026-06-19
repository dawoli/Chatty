#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s;
int main() {
	freopen("poker.in","r","stdin");
	freopen("poker.out","w","stdout");
	int n;
	cin >> n; 
	for(int i = 0; i <= s.size(); i++) {
		cin >> s;
	}
	cout << 52 - n;
}
