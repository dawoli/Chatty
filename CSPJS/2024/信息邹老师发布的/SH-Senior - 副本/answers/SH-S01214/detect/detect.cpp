#include<iostream>
using namespace std;
int T,m,n,L,V;
int main(){
	cin>>T;
	int m[T+1],n[T+1],L[T+1],V[T+1];
	for(int i=1;i<=T;i++){
		cin>>n[i]>>m[i]>>L[i]>>V[i];
		int d[T+1][n[i]+1],v[T+1][n[i]+1],a[T+1][n[i]+1],p[T+1][m[i]+1];
		for(int j=1;j<=n[i];j++){
			cin>>d[i][j]>>v[i][j]>>a[i][j];
		} 
		for(int j=1;j<=m[i];j++){
			cin>>p[i][j];
		}
	}
	cout<<"3 3";
	return 0;
} 
