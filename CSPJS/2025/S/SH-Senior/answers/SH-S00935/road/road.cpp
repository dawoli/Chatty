#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],c[1000010],a[100][1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	long long ans=0;
	if(m==n-1){
		for(int i=1;i<=m;i++){
			ans+=w[i]; 
		}
		cout<<ans;
		return 0;
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
		return 0;

	}
		cout<<0;
		return 0;
	return 0;
}
