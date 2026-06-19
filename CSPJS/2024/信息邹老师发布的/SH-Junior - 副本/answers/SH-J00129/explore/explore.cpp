#include <bits/stdc++.h>
using namespace std;
int m,n,k,t,ox,oy,od,ans;
char a;
int f[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long mp[1020][1020],v[1020][1020];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>ox>>oy>>od;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a;
				if(a=='.')mp[i][j]=1;
				else mp[i][j]=0;
			}
		}

		v[ox][oy]=1;
		ans++;
		for(int i=k;i>0;i--){
			int nx=ox+f[od][0];
			int ny=oy+f[od][1];
			if(nx<1||ny<1||nx>n||ny>m||mp[nx][ny]==0){
				od++;
				od%=4;
				continue;
			}
			ox=nx;
			oy=ny;
			if(v[ox][oy]==0)ans++;
			v[ox][oy]++;
			
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				v[i][j]=0;
				mp[i][j]=0;
			}
		}
		ans=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
