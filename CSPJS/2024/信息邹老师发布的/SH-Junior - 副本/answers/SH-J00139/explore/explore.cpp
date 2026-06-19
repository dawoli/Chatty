#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,s,f[1145][1145];
char a[1145][1145];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(f,0,sizeof(f));s=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				a[i][j]=getchar();
			}
		}f[x][y]=1;
		for(int i=1;i<=k;i++){
			int dx=x,dy=y;
			if(d==0) dy++;
			if(d==1) dx++;
			if(d==2) dy--;
			if(d==3) dx--;
			if(dx<=n && dy<=m && dx>0 && dy>0 && a[dx][dy]!='x'){
				x=dx,y=dy;f[x][y]=1;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]) s++;
			}
		}cout<<s<<endl;;
	}
	return 0;
}
