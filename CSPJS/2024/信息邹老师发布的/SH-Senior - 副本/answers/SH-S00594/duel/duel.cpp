#include<bits/stdc++.h>
using namespace std;
int n,ans;
unordered_map <int,int> mp; 
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		mp[r]++;
	}
	for(auto x:mp) ans=max(ans,x.second);
	cout<<ans;
}
