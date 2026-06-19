#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<string> s;
ll n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		string str;
		cin>>str;
		s.insert(str);
	}
	cout<<52-s.size();
	return 0;
}
