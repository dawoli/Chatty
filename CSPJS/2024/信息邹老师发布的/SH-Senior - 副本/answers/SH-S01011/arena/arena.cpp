#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N],c[N];
int n,m,t;
int ans;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	cin>>t;
	while(t--){
		int x1,x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		cout<<ans;
	}
	return 0;
}
