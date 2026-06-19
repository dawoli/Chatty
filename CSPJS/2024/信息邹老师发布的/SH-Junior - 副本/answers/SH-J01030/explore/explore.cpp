#include<iostream>
using namespace std;
const int N=1003;
int t,n,m,k;
int a,x,y,d;   //a ´ð°¸ 
bool vis[N][N];
char gra[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool che(int x,int y){
	if(x<1||x>n||y<1||y>m) return false;
	else return gra[x][y]=='.';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int tes=1;tes<=t;tes++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>gra[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vis[i][j]=0;
		vis[x][y]=1;
		for(int i=1;i<=k;i++){
			int nx=x+dx[d];
			int ny=y+dy[d]; 
			if(!che(nx,ny)) d=(d+1)%4;
			else{
				x=nx;
				y=ny;
				vis[x][y]=1;
			}
		}
		a=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a+=vis[i][j];
		cout<<a<<endl;
	}
} 
