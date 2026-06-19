#include<bits/stdc++.h>
using namespace std;
long long t;
char ma[1005][1005];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,m,k,nx,ny,d,ans=0;
		cin>>n>>m>>k>>nx>>ny>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		ma[nx][ny]='1';
		for(int i=1;i<=k;i++){
			nx+=dx[d];
			ny+=dy[d];
			if(nx<1||nx>n||ny<1||ny>m||ma[nx][ny]=='x'){
				nx-=dx[d];
				ny-=dy[d];
				d=(d+1)%4;
				continue;
			}
			ma[nx][ny]='1';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ma[i][j]=='1'){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
