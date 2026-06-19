#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 1111
int t,n,m,k,x,y,d,a[N][N],
dx[11]={0,1,0,-1},
dy[11]={1,0,-1,0},
ans;
bool b[N][N][4];
int main(){
	open("explore");
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=0;i<=n+1;i++)
			a[i][0]=1,a[i][m+1]=1;
		for(int i=0;i<=m+1;i++)
			a[0][i]=1,a[n+1][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				a[i][j]=(c=='x');
			}
		memset(b,0,sizeof(b));
		b[x][y][d]=1;
		while(k--){
			if(a[x+dx[d]][y+dy[d]])d=(d+1)%4;
			else{
				x+=dx[d],y+=dy[d];
				if(b[x][y][d])break;
				b[x][y][d]=1;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=b[i][j][0]|b[i][j][1]|b[i][j][2]|b[i][j][3];
		cout<<ans<<endl;
	}
}
