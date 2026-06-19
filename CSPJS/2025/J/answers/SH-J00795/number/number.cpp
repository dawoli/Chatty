#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll x[1009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		x[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		while(x[i]){
			cout<<i;
			x[i]--;                    
		}
	}
	return 0;
}
