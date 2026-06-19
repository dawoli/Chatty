#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
string s;
vector<char> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>s;
	for(auto c:s){
		if((c>='0')&&(c<='9')){
			v.pb(c);
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	cout<<'\n';
	return 0;
} 
