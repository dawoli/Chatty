#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
string k;
set<string> s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>k;
		s.insert(k);
	}
	cout<<52-s.size();
	return 0;
}
