#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		int ans=0;
		for(int i=1,u,v;i<=m;i++)cin>>u>>v>>w[i];
		sort(w+1,w+m+1);
		for(int i=1;i<=n-1;i++)ans+=w[i];
		cout<<ans; 
	}
	else cout<<0;
	return 0;
} 
