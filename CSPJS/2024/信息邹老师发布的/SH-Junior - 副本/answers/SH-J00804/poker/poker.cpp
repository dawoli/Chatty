#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
int n,ans;
string s;
map<int,bool> mp;
int ha(string s){
	return s[0]*128+s[1];
}
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	rep(i,1,n){
		cin>>s;
		int t=ha(s);
		if(!mp[t])ans++;
		mp[t]=true;
	}
	cout<<(52-ans)<<endl;
	return 0;
}
