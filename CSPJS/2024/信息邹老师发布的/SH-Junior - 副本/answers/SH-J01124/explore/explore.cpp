#include<bits/stdc++.h>
using namespace std;
long long T;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
long long n,m,k,x,y,d,ans[6],cnt,g;
char c[10009][10009];
bool vst,area[10009][10009];
void go(int x,int y,int d,int t){
	 if(t>=k){ans[g]=cnt;vst=1;}
	 if(vst) return;
     int nx=x+dx[d],ny=y+dy[d];
     if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&c[nx][ny]=='.'){
     	if(!area[nx][ny]){
		cnt++;
		area[nx][ny]=1;
	}
     	go(nx,ny,d,t+1);
	 }
     else{
     	d=(d+1)%4;
     	go(x,y,d,t+1);
	 }
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(g=0;g<T;g++){
		cnt=1;
		vst=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		area[x][y]=1;
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++) cin>>c[i][j];
		go(x,y,d,0);
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=m;j++){
		   c[i][j]=0;
		   area[i][j]=0;
		    }
	}
	for(int i=0;i<T-1;i++) cout<<ans[i]<<endl;
	cout<<ans[T-1];
	return 0;
} 
