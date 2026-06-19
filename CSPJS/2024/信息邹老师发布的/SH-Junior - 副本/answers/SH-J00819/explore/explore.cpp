#include<bits/stdc++.h>
using namespace std;
bool b[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		long long ans=1;
		long long n,m,k;
		cin>>n>>m>>k;
		long long x,y,d;
		cin>>x>>y>>d;
		b[x][y]=1;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(long long i=1;i<=k;i++){
			bool flag=1;
			long long nx=x,ny=y;
			if(d==0)ny++;
			if(d==1)nx++;
			if(d==2)ny--;
			if(d==3)nx--;
			if(nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')flag=0;
			if(flag){
				x=nx,y=ny;
				if(!b[x][y]){
					ans++;
					b[x][y]=1; 
				}
			}
			else{
				d=(d+1)%4; 
			}
		}
		cout<<ans<<endl;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				b[i][j]=0;
			}
		}
	}
	return 0;
}
