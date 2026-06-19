#include<bits/stdc++.h>
using namespace std;
int ans[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.length();i++){
		if('0' <= s[i] && s[i] <= '9'){
			ans[(s[i]-'0')]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(ans[i]){
			cout<<i;
			ans[i]--;
		}
	}
	cout<<endl;
	return 0;
}
