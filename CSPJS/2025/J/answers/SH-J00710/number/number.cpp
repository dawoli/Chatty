#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+30;
char s[N];
int a[20];

int main(){
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < sizeof(s); i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			cout << i;
		}
	}
	return 0;
}
