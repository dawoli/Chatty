#include <bits/stdc++.h>
using namespace std;
string s,ans="";
int flag,a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<s.length();i++){
		if ('0'<=s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=a[i];j++){
			ans+=(char)(i)+'0';
		}
	}
	cout << ans;
	return 0;
}
