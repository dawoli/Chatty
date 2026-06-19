#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int n,ans;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		if(mp[s]==0){
			mp[s]=1;
			++ans;
		}
	}
	cout<<52-ans<<endl;
	return 0;
}
