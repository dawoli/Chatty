#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ans[20];
	cin >> s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if('0' <= s[i] && '9' >= s[i]){
			int a = s[i] - 48;
			ans[a]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 0;j < ans[i];j++){
			cout << i;
		}
	}
	return 0;
}
