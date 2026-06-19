#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t = 0,a[1145140];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(ll i = 0;i < s.length();i++){
		if('0' <= s[i] && s[i] <= '9') a[++t] = s[i]-'0';
	}
	sort(a+1,a+1+t);
	for(ll i = t;i >= 1;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
