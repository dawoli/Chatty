#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
char ma[1010][1010];
bool vis[1010][1010];
void dfs(int x,int y,int d,int k){
	if(k>0){
		bool flag=true;
	    int nx,ny;
	    if(d==0){
	    	nx=x;
	    	ny=y+1;
		}
		if(d==1){
			nx=x+1;
			ny=y;
		}
		if(d==2){
			nx=x;
			ny=y-1;
		}
		if(d==3){
			nx=x-1;
			ny=y;
		}
	    //cout<<nx<<" "<<ny<<endl;
	    if(nx>n||ny>m||nx<=0||ny<=0){
	    	d=(d+1)%4;
	    	dfs(x,y,d,k-1);
	    	flag=0;
		}
	    if(ma[nx][ny]=='x'){
	    	d=(d+1)%4;
	    	dfs(x,y,d,k-1);
	    	flag=0;
		}
		if(flag){
			vis[nx][ny]=1;
			dfs(nx,ny,d,k-1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0;
	    cin>>n>>m>>k;
	    cin>>x>>y>>d;
	    vis[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		dfs(x,y,d,k);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]){
					ans++;
					//cout<<i<<" "<<j<<endl;
					vis[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
