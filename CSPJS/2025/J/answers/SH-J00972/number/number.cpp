#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
string s;
int a[1000005], cnt = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[cnt++] = s[i] - '0';
		}
	}
	sort(a, a + cnt, cmp);
	if(a[0] == 0){
		cout << 0;
		return 0;
	}
	for(int i = 0;i < cnt;i++){
		cout << a[i];
	}
	return 0;
}
