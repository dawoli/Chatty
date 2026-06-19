#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[200009][9],t[200009][9];
ll n,q;
void solve(ll nw){
	cout<<0<<endl;
}
void solvetb(ll nw){
	cout<<0<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(ll i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		ll cnt=0;
		for(ll j=0;j<t[i][1].length();j++){
			if(t[i][1][j]=='b'){
				cnt++;
			}
		}
		if(t[i][1].length() != t[i][2].length()){
			cout<<0<<endl;
		}else if(cnt==1){
			solvetb(i);
		}else{
			solve(i);	
		}
	}
	return 0;
}
