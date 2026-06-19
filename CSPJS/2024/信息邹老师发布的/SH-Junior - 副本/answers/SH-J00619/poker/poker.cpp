#include<iostream>
using namespace std;
typedef long long ll;
bool a[128][128];
string S="DCHS",T="A23456789TJQK";
int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ll t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		a[s[0]][s[1]]=1;
	}
	ll cnt=0;
	for(ll i=0;i<4;i++) for(ll j=0;j<13;j++) {
		if(!a[S[i]][T[j]]) cnt++;
	}
	cout<<cnt;
	return 0;
}
