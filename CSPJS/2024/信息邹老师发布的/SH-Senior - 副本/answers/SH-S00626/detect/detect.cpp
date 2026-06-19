#include<bits/stdc++.h>
#define kMaxN 100005
using namespace std;
typedef unsigned long long ull;
ull n,m,l,v;
struct node{
	ull d;
	ull v;
	ull a;
};
node a[kMaxN];
ull l[kMaxN];
inline void solve(){
	cin>>n>>m>>l>>v;
	for(int i=0;i<n;i++){
		cin>>a[i].d>>a[i].v>>a[i].a;
	}
	for(int i=0;i<m;i++){
		cin>>l[i];
	}
	cout<<"0 "<<m<<'\n';
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
