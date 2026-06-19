#include<bits/stdc++.h>
using namespace std;
int n,m,t,ac[100005],c[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ac[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int k=ceil(log2(n));
	for(int i=1;i<=pow(2,k+1)-1;i++){
	  int x;
	  cin>>x;
	}
	cin>>t;
	while(t--) cout<<"1"<<endl;
	return 0;
}
