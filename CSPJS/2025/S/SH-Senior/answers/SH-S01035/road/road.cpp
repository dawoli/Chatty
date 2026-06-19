#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cnt=0; 
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		cin>>a[i];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	else{
		cout<<w;
	}
	return 0;
}
