//O(n^2) 60pts
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=1e3+3;
int n,ans=1,k;
int a[maxn],g[maxm][maxm];
vector<pair<int,int> > v;
bool cmp(pair<int,int> _a,pair<int,int> _b){
	return _a.second<_b.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		g[i][i]=a[i];
		if(g[i][i]==k) v.push_back({i,i});
		for(int j=i+1;j<=n;j++){
			g[i][j]=g[i][j-1]^a[j];
			if(g[i][j]==k) v.push_back({i,j});
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(!v.size()){
		puts("0");
		return 0;
	}
	pair<int,int> now;
	now.first=v[0].first;now.second=v[0].second;
	for(int i=1;i<(int)v.size();i++){
		if(v[i].first>now.second){
			now.first=v[i].first,now.second=v[i].second;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}