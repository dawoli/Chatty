#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,pair<int,int>>> sss;
vector<vector<pair<int,int>>> a(1000,vector<pair<int,int>>(1000));
int main(){
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	int n,m,k,p,q,t;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p>>q>>t;
		a[p].push_back(make_pair(q,t));
		a[q].push_back(make_pair(p,t));
	}
	for(int i=1;i<=k;i++){
		cin>>p;
		for(int i=1;i<=n;i++){
			cin>>q;
			a[k].push_back(make_pair(i,q));
			a[i].push_back(make_pair(k,q));
		}
	}
	int ans=0;
	for(auto i:a){
		for(auto j:i){
			ans+=j.second;
		}
	}
	ans%=p+q+t;
	cout<<ans;
	return 0; 
}
