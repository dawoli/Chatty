#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1005][1005];
bool f[1005][1005];
int main(){
	freopen("explore.in","r",stdin);freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(f,0,sizeof f);
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int nx=x;
		int ny=y,ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		f[x][y]=1;
		while(k--){
			if(d==0){
				if(ny+1>m||a[nx][ny+1]=='x') d=(d+1)%4;
				else{
					ny++;
					f[nx][ny]=1;
				}
			}
			else if(d==1){
				if(nx+1>n||a[nx+1][ny]=='x') d=(d+1)%4;
				else{
					nx++;
					f[nx][ny]=1;
				}
			}
			else if(d==2){
				if(ny-1<1||a[nx][ny-1]=='x') d=(d+1)%4;
				else{
					ny--;
					f[nx][ny]=1;
				}
			}
			else if(d==3){
				if(nx-1<1||a[nx-1][ny]=='x') d=(d+1)%4;
				else{
					nx--;
					f[nx][ny]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(f[i][j]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
