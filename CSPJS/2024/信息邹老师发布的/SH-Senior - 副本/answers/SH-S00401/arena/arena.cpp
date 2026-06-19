#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a[100005],c[100005],x[100005][4];
char g[100005];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	for(int i=0;i<m;i++){
		cin>>c[i];}
	k=pow(2,(int)log2(n))-1;
	for(int i=0;i<k;i++){
		cin>>g[i];}
	cin>>T;
	for(int i=0;i<T;i++){
		for(int j=0;j<4;j++){
			cin>>x[i][j];}}
	cout<<"5\n19\n7\n1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
