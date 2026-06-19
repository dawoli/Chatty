#include<bits/stdc++.h>
using namespace std;
int T;
int a[1010][1010];
int vis[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct u{
	int x,y,z;
};
int n,m,k;
int slove(int x,int y,int z){
	queue<u> q;
	q.push({x,y,z});
	int ans=1;
	vis[x][y]=1;
	while(!q.empty() && k>0){
		u f=q.front();
		q.pop();
		int dz=f.z,s=0;
		while((a[f.x+dx[dz]][f.y+dy[dz]]==1 || f.x+dx[dz]<1 || f.x+dx[dz]>n || f.y+dy[dz]<1 || f.y+dy[dz]>m)&& k>0){
			dz=(dz+1)%4;
			k--;
			if(dz==f.z){
				s=1;
				break;
			}
		}
		if(k<=0 || s==1){
			return ans;
		}
		int fx=f.x,fy=f.y;
		while(fx+dx[dz]>=1 && fx+dx[dz]<=n &&fy+dy[dz]>=1 && fy+dy[dz]<=m && a[fx+dx[dz]][fy+dy[dz]]==0 && k>0){
			if(a[fx+dx[dz]][fy+dy[dz]]==0 && k>0){
				if(!vis[fx+dx[dz]][fy+dy[dz]]) ans++;
				k--;
				fx=fx+dx[dz];
				fy=fy+dy[dz];
				vis[fx][fy]=1;	
			}			
		}
		if(k<=0) return ans;
		q.push({fx,fy,dz});
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		int rx,ry,rz;
		cin>>n>>m>>k;
		cin>>rx>>ry>>rz;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='.') a[i][j]=0;
				if(c=='x') a[i][j]=1;
			}
		}
		cout<<slove(rx,ry,rz)<<"\n";
	}
	return 0;
}
