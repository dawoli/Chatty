#include<bits/stdc++.h>
int a[10];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout << i;
		}
	}
	return 0;
}
