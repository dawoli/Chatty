#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c[1000001];
	string s;
	int len = 0;
	cin >> s;
	for(char ch : s) {
		if(isdigit(ch))  c[++len] = ch;
	}
	sort(c+1,c+len+1);
	for(int i=len;i>=1;--i) cout << c[i];
	cout << endl;
}
