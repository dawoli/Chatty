#include <bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if('0' <= s[i]&&s[i] <= '9'){
			a[s[i]-'0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
