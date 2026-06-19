#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	vector<ll> a;
	for(ll i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(ll i=a.size()-1;i>=0;i--) cout<<a[i];
	return 0;
}
