#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=99;
ll n;
string s[N];
void solve(){
	set<string> ps;
	for(ll i=1;i<=n;i++)
		ps.insert(s[i]);
	cout<<(52-ps.size())<<endl;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>s[i];
	if(n==1)
		cout<<51<<endl;
	else
		solve();
	return 0;
}
