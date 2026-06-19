#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f3f3f;
int n,m,t;
char a[1010][1010];
int vis[1010][1010],s[1010][1010],s1[1010][1010];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
	int x,y;
};
void BFS(int x,int y){
	for(int i=0;i<1010;i++){
		for(int j=0;j<1010;j++){
			vis[i][j]=0;
			s[i][j]=0;
			s1[i][j]=0;
		}
	}
	queue<node> Q;
	Q.push({x,y});
	vis[x][y]=1;
	while(!Q.empty()){
		node u=Q.front();
		Q.pop();
		int nx=u.x,ny=u.y;
		for(int i=0;i<4;i++){
			nx+=dx[i];
			ny+=dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]||a[nx][ny]=='*'){
				continue;
			}
			else{
				s[nx][ny]=s[u.x][u.y]+(a[nx][ny]=='$');
				s1[nx][ny]=s1[u.x][u.y]+1;
				vis[nx][ny]=1;
				Q.push({nx,ny});
			}
		}
	}
} 
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		BFS(0,0);
		cout<<s[n-1][m-1]<<" "<<s1[n-1][m-1]<<endl;
	}
	return 0;
} 
