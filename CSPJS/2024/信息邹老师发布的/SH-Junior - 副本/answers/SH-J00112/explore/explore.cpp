#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,d;long long t;
bool v[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		cin>>n>>m>>k>>x>>y>>d;
		v[x][y]=1;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		while(k--){
			if(d==0){
				if(y+1<=m&&a[x][y+1]=='.') y++;
				else d=(d+1)%4;
			}
			else if(d==1){
				if(x+1<=n&&a[x+1][y]=='.') x++;
				else d=(d+1)%4;
			}
			else if(d==2){
				if(y-1>=1&&a[x][y-1]=='.') y--;
				else d=(d+1)%4;
			}
			else{
				if(x-1>=1&&a[x-1][y]=='.') x--;
				else d=(d+1)%4;
			}
			v[x][y]=1;
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				if(v[i][j]==1) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
