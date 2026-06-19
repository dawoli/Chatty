#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[int(5.1e5)],b[int(5.1e5)];
ll n,x;
ll premax[int(5.1e5)]={0}; 
inline ll q(int x,int y){
	return b[y]^b[x-1];//qian zui yi huo he cha xun 
}
//qing chuan li li tu bo shu
//fang cao qi qi san jiao zhou 
//xi ren yi chen tu bo qu
//ci di kong yu xjh
map<ll,pair<ll,ll > > mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
		premax[i]=premax[i-1];
		ll target=(x^b[i]);
		premax[n]=max(premax[n],mp[target].second+1);
		mp[b[i]].second=max(mp[b[i]].second,premax[n]);
	}
	//O(n*lg n)
	cout<<premax[n];
}
