#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ln,c,box[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ln=s.size();
	s=" "+s;
	for(ll i=1;i<ln;i++){
		if('0'<=s[i] && s[i]<='9'){
			box[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=box[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
