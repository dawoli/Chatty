#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int n,m,k,t,h,x,y,d,f[1005][1005];
int nxt[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){	
				cin>>a[i][j];
				f[i][j]=0;
		}} 
		h=1,f[x][y]=1;
		for(int i=1;i<=k;i++){
			int p=x+nxt[d][0],q=y+nxt[d][1];
			if(p<1 || p>n || q<1 || q>m || a[p][q]=='x') d=(d+1)%4;
			else{
				x=p,y=q;f[x][y]++;
				if(f[x][y]==1) h++;
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
