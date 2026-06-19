#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
char ch;
map <int,int> n;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while(cin >> ch) {
		if(ch >= '0' && ch <= '9') {
			n[ch-'0']++;
		}
	}
	
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= n[i];j++)
			cout << i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return cout << "\n", 0;
}
