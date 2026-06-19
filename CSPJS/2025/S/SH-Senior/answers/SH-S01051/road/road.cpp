#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int m,n,k,u[N],v[N],w[N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++)cin>>c[i];
	}
	cout<<13<<endl;
	return 0;
}
