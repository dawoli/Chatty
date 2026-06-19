#include<bits/stdc++.h>
#include<set>
using namespace std;

int n;
string s;
set<string> c;

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		c.insert(s);
	}
	cout << 52-c.size();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

