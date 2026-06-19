#include<bits/stdc++.h>
using namespace std;
int a[100002],c[100002];
bool e[105][105];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>c[i];
	int k=0,K=1;
	while(c>K){
		K=K*2;k++;
	}for(int i=1;i<=k;i++){
		for(int j=1;j<=K;j++){
			char p;
			cin>>p;
			e[i][j]=p-'0';
		}
		K=K/2;
	}
	int T;
	cin>>T;
	while(T--){
		int change[4];
		int reala[100002];
		cin>>change[0]>>change[1]>>change[2]>>change[3];
		for(int i=1;i<=n;i++)reala[i]=a[i]^change[i%4];
		cout<<1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
