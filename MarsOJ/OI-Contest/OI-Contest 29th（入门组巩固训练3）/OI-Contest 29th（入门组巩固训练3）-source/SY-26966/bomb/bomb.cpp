#include<bits/stdc++.h>
using namespace std;
int t,n,m,dx[4]={1,0,-1,0},dy[4]={0,-1,0,1},dis[1005][1005];
char mp[1005][1005];
struct node{
	int x,y,bomb_num;
};
queue<node>Q;
bool vis[1005][1005];
bool check(int x){
	memset(vis,0,sizeof(vis));
	while(!Q.empty()){
		Q.pop();
	}
	node sb;
	sb.x=1;
	sb.y=1;
	sb.bomb_num=x;
	Q.push(sb);
	vis[1][1]=1;
	while(!Q.empty()){
		node u=Q.front();
		Q.pop();
		int x=u.x;
		int y=u.y;
		if(x==n&&y==m){
			return true;
		}
//		cout<<x<<" "<<y;
		int b_n=u.bomb_num;
		for(int i=0;i<4;i++){
			int vx=x+dx[i];
			int vy=y+dy[i];
			if(vx<1||vx>n||vy<1||vy>m){
//				cout<<vx<<" "<<vy<<endl;
				continue;
			}
			if(vis[vx][vy]){
				continue;
			}
			if(mp[vx][vy]=='*'){
				continue;
			}
			if(mp[vx][vy]=='$'&&b_n<=0){
				continue;
			}
//			cout<<vx<<" "<<vy<<" "<<b_n<<" "<<dx[i]<<" "<<dy[i]<<" "<<n<<" "<<m<<" "<<(n==vx)<<" "<<(m==vy)<<" "<<(vx==n&&vy==m)<<endl;
			if(vx==n&&vy==m){
				return 1;
			}
			node tmp;
			tmp.x=vx;
			tmp.y=vy;
			tmp.bomb_num=b_n-(mp[vx][vy]=='$');
			vis[vx][vy]=1;
			Q.push(tmp);
		}
	}
	return false;
}
int main(){
//	freopen("bomb.in","r",stdin);
//	freopen("bomb.out","w",stdout);
	freopen("3.in","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			char c;
			for(int j=1;j<=m;j++){
				cin>>c;
				mp[i][j]=c;
			}
		}
		int l=0,r=1000000,ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
//			cout<<endl<<endl;
//			cout<<l<<" "<<r<<endl;
		}
		cout<<ans<<" ";
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		while(!Q.empty()){
			Q.pop();
		}
		node sb;
		sb.x=1;
		sb.y=1;
		sb.bomb_num=ans;
		Q.push(sb);
		vis[1][1]=1;
		while(!Q.empty()){
			node u=Q.front();
			Q.pop();
			int x=u.x;
			int y=u.y;
			if(x==n&&y==m){
				break;
			}
	//		cout<<x<<" "<<y;
			int b_n=u.bomb_num;
			for(int i=0;i<4;i++){
				int vx=x+dx[i];
				int vy=y+dy[i];
				if(vx<1||vx>n||vy<1||vy>m){
	//				cout<<vx<<" "<<vy<<endl;
					continue;
				}
				if(vis[vx][vy]){
					continue;
				}
				if(mp[vx][vy]=='*'){
					continue;
				}
				if(mp[vx][vy]=='$'&&b_n<=0){
					continue;
				}
	//			cout<<vx<<" "<<vy<<" "<<b_n<<" "<<dx[i]<<" "<<dy[i]<<" "<<n<<" "<<m<<" "<<(n==vx)<<" "<<(m==vy)<<" "<<(vx==n&&vy==m)<<endl;
				dis[vx][vy]=dis[x][y]+1;
				if(vx==n&&vy==m){
					break;
				}
				node tmp;
				tmp.x=vx;
				tmp.y=vy;
				tmp.bomb_num=b_n-(mp[vx][vy]=='$');
				vis[vx][vy]=1;
				Q.push(tmp);
			}
		}
		cout<<dis[n][m]<<endl;
	}
	return 0;
}

