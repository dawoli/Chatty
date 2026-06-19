#include<bits/stdc++.h>
using namespace std;
const int dir[4][2]={0,1,1,0,0,-1,-1,0};
int t,n,m,x,y,d,ans,k;
bool a[1010][1010],book[1010][1010];
char op;
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
bool bj(int x,int y){
	return x>=1 && x<=n && y>=1 &&y<=m;
}
void freopen(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
}
void work(int x,int y,int d){
	int nx=0,ny=0,nd=0;
	for(int i=1;i<=k+1;i++){
		if(!book[x][y]) book[x][y]=1,ans++;
        nx=x+dir[d][0];
	    ny=y+dir[d][1];
	    nd=(d+1)%4;
	    if(bj(nx,ny)&&a[nx][ny]) x=nx,y=ny;
	    else d=nd;
	}
	return ;
}
int main(){
	freopen();
	sync();
	cin>>t;
	while(t--){
		for(int i=1;i<=1000;i++)
			for(int j=1;j<=1000;j++) 
				book[i][j]=0,a[i][j]=0;
	    ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>op;
				if(op=='.') a[i][j]=1;
				else a[i][j]=0;
			}
		}
		work(x,y,d);
		cout<<ans<<"\n";
	}
	return 0;
}
