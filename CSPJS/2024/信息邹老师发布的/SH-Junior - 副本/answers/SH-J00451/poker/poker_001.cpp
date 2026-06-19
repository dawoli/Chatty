#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int> mp;
string x;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(mp[x]!=1)ans++;
		mp[x]=1;
	}
	ans=52-ans;
	cout<<ans;
	return 0;
}
