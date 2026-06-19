#include<bits/stdc++.h>
using namespace std;
string s;
int n[10];
int main() {
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for (char i:s) {
		if (48<=i && i<=57) n[i-48]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < n[i]; j++) cout << i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
