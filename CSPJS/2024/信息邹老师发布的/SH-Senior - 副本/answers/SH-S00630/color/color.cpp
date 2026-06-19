#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	map<int,int> ma;
	map<int,int>::iterator it;
	int n;
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		ma[x]++;
	}
	int ans=0;
	for(it=ma.begin();it!=ma.end();it++){
		ans+=it->first*(it->second-1);
	}
	cout<<ans<<"\n";
	return ;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
