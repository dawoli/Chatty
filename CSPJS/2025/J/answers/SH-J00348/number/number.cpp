#include<bits/stdc++.h>
using namespace std;
string s,ans;
vector<char> cnt;
bool flag=true;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(auto u:s)
		if('0'<=u&&u<='9'){
			cnt.push_back(u);
			if(u!='0') flag=false;
		}
	if(flag){
		cout<<"0\n";
		return 0;
	}
	sort(cnt.begin(),cnt.end());
	reverse(cnt.begin(),cnt.end());
	for(auto u:cnt) cout<<u;
	return 0;
}
