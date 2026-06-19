#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt,b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	ll l=s.length();
	for(ll i=0; i<l; i++)	if(isdigit(s[i])) b[cnt++]=s[i]-'0';
	sort(b,b+cnt);
	for(ll i=cnt-1; i>=0; i--) cout << b[i];
	return 0;
}
