#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i = 0;i < (int)s.size();i++){
		if ('0' <= s[i] && s[i] <= '9') cnt[s[i]-'0']++;
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= cnt[i];j++){
			cout<<i;
		} 
	}
	cout<<endl;
	return 0;
}
