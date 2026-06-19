#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define el <<"\n"
using namespace std;
typedef long long ll;
/*
尽量选最优的
如果不满足，至多一种不满足
按照移到别的组损失从小到大排序调整 
*/
void solve(){
	int n;
	cin>>n;
	ll ans=0;
	priority_queue<int>S1,S2,S3;
	rep(i,1,n){
		int x,y,z;
		cin>>x>>y>>z;
		int mx=max(x,max(y,z));ans+=mx;
		if(x==mx)S1.push(max(y,z)-mx);
		else if(y==mx)S2.push(max(x,z)-mx);
		else S3.push(max(x,y)-mx);
	}
	while(S1.size()>n/2){
		ans+=S1.top();
		S1.pop();
	}
	while(S2.size()>n/2){
		ans+=S2.top();
		S2.pop();
	}
	while(S3.size()>n/2){
		ans+=S3.top();
		S3.pop();
	}
	cout<<ans el;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
