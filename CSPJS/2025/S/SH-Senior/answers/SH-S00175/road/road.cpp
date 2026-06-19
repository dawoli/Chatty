#include<bits/stdc++.h>
using namespace std;
const int M=100009;
const int N=10009;
const int K=19;
int n,m,k,u[M],v[M],w[M],c[K],a[K][N];
bool A(){
	for(int i=1;i<=k;i++)if(c[i]!=0)return false;
	for(int i=1;i<=k;i++){
		bool flag=true;
		for(int j=1;j<=n;j++)if(a[i][j]==0){flag=false;break;}
		if(flag)return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(A()){
		
	}
	return 0;
}
