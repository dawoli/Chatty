#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s;
vector<int> g;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') g.push_back(s[i]-'0');
	sort(g.begin(),g.end());
	for(int i=g.size()-1;i>=0;i--) cout<<g[i];
	return 0;
}
