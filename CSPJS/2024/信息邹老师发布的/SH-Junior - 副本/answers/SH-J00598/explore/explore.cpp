#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
bool vst[1010][1010];
char c[1010][1010];
int main(){
	ios::sync_with_stdio(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(vst,0,sizeof(vst));
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		for(k;k>=0;k--){
		//	cout<<x<<' '<<y<<' '<<d<<'\n';
			cnt+=!vst[x][y]; 
			vst[x][y]=true;
			int xx=x+dx[d],yy=y+dy[d];
			if(xx<=n and xx>=1 and yy>=1 and yy<=m and c[xx][yy]=='.'){
				x=xx;y=yy;
			//	cout<<x<<' '<<y<<"\n\n";
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

