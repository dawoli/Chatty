#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i : s){
		if(i>='0'&&i<='9'){
			v.push_back(signed(i-'0'));
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
