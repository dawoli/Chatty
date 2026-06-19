#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		mp[t]++;
		ans=max(mp[t],ans);
	}
	cout<<ans;
	return 0;
}

