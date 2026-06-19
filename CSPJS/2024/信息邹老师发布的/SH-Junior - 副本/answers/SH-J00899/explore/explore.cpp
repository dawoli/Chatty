#include<bits/stdc++.h>

using namespace std;

ifstream fin("explore.in");
ofstream fout("explore.out");
#define cin fin
#define cout fout

const int N=1e3+9;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

int a[N][N],vis[N][N],n,m,k;
void Work(int &x,int &y,int &d){
	int xx=x+dx[d],yy=y+dy[d];
	if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]) d=(d+1)%4;
	else x=xx,y=yy;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int x,y,d,ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='.') a[i][j]=0;
				else a[i][j]=1;
				vis[i][j]=0;
			}
		}
		ans++,vis[x][y]=1;
		while(k--) Work(x,y,d),ans+=!vis[x][y],vis[x][y]=1;
		cout<<ans<<endl;
	}
	
	return 0;
}
