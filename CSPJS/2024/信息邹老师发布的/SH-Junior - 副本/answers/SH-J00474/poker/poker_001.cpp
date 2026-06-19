#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<string> s;
ll n;
string t;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>t;
		s.insert(t);
	}
	cout<<52-s.size();
	return 0;
} 
