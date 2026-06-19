#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
map<string,string>mp;
string x,y;
string mp1,mp2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (ll i=1;i<=n;i++){
		cin>>mp1>>mp2;
		mp[mp1]=mp2;
	}
	while (q--){
		cin>>x>>y;
		ll ans=0;
		for (ll i=0;i<x.size();i++){
			for (ll j=i;j<x.size();j++){
				string tmp=x.substr(i,j-i+1);
				if (mp[tmp].size()>0){
					string news=x.substr(0,i)+mp[tmp]+x.substr(j+1,x.size()-j);
					if (news==y){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
