#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10;
string s;
vector<ll> v;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for(ll i=0;i<s.size();i++) if('0'<=s[i] && s[i]<='9') v.push_back(s[i]-'0');
	sort(v.begin(),v.end());
	for(ll i=v.size()-1;i>=0;i--) cout<<v[i];
	
	return 0;
}
