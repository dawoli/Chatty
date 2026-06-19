#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int a[N];
int main (){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < N; i++){
		if (s[i] == 0) break;
		if (s[i] >= 48 && s[i] <= 57) a[cnt++] = s[i] - 48;
	}
	cnt -= 1;
	sort (a, a + cnt + 1);
	for (int i = cnt; i >= 0; i--){
		cout << a[i];
	}
	return 0;
}
