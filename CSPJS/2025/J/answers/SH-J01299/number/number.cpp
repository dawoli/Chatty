#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000009]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	ll k=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')
			a[++k]=(ll)(s[i]-'0');
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--) cout<<a[i];
	return 0;
}
