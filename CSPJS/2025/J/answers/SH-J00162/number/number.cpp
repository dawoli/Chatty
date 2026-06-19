#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
string s,ans="";
vector<int> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			v.push_back(s[i]-'0');
	}
	sort(v.begin(),v.end());
	for(auto p:v)
		ans+=(p+'0');
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i];
	return 0;
}

