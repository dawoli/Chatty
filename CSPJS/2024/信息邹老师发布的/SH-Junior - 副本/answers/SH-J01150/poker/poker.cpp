#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	ll n;
	cin>>n;
	
	set<string> rd;
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
		rd.insert(s);
	}
	
	cout<<52-rd.size();
	
	return 0;
}
