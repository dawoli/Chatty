#include<bits/stdc++.h>
using namespace std;

char a[1000010];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int cnt = 0;
	cin >> s;
	int m = s.size();
	for(int i = 0; i < m; i++){
		int t = s[i];
		if(t >= 48 && t <= 57)
		a[++cnt] = s[i];
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i >= 1; i--) cout << a[i];
	return 0;
}
