#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string s;
int n;
int a[1000010], m = 0;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i ++){
		if(s[i] <= '9' && s[i] >= '0')a[++m] = s[i] - '0';
	}
	sort(a + 1, a + m + 1);
	for(int i = m; i >= 1; i --)cout << a[i];
	return 0;
}
