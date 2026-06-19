#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[20];
string s;

void solve(){
	cin>>s;
	s=' '+s;
	n=s.size();
	for(int i=1;i<=n;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;--i){
		while(a[i]--){
			cout<<i;
		}
	}
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
