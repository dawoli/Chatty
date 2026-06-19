#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,a[100005];
	int ans=0;
	bool f[100005]={0};
	map <int,int> mp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(auto it:mp){
		int del=min(ans,it.second);
		ans=ans+it.second-del;
	}
	//sort(a,a+n);
	
	cout<<ans;
	return 0;
} 
