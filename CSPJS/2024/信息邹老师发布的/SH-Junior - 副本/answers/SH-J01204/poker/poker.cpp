#include <bits/stdc++.h>
using namespace std;
int n, ans = 52, judge = 0;
string s[53];
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		ans --;
		for(int j = 1; j < i; j ++){
			if(s[j] == s[i]){
				ans ++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
