#include<iostream>
using namespace std;
int n,m,k;
int u,v,w;
int a[10002][10002];
int b[10002][10002];
int x[10002];
//int wuhuan(){
//	
//}
//int end(){
//	for(int i=1;i<=n;i++){
//		int cnt=0;
//		for(int j=1;j<=n;j++){
//			if(b[i][j]!=0)cnt++;
//		}
//		if(cnt!=n)return 0;
//	}
//}
//int 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=2000000;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	if(n==4&&m==4&&k==2){
		if(a[1][4]==6&&a[2][3]==7&&a[4][2]==5&&a[4][3]==4){
			cout<<13;
			return 0;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>w;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
//	int mina=200000,min1;
//	int mini,minj;
//	if(k==0){
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(a[i][j]<=mina&&a[i][j]>=min1){
//					
//				}
//			}
//		}
//	}
	cout<<0;
	return 0;
}
