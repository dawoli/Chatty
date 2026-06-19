#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int num[N], cnt;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			num[++cnt] = s[i] - '0';
	sort(num + 1, num + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
		cout << num[i];
	cout << endl;
	return 0;
}

