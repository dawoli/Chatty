#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
set<string> se;
void input(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>s;
		se.insert(s);
	}
}
void solve(){
	cout<<52-se.size();
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	input();
	solve();
	return 0;
}

