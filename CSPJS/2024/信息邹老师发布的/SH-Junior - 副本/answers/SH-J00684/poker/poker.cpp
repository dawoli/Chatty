#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll t;
map<string,ll> mp;
ll cnt=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		mp[a]++;
		if(mp[a]==1){
			cnt++;
		}
	}
	cout<<52-cnt<<endl;
}
