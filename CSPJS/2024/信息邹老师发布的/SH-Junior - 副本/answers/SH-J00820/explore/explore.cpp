#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
bool vst[1009][1009],Cpass[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
 	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='.') Cpass[i][j]=1;
				else Cpass[i][j]=0;
			}
		int ans=1;
		memset(vst,0,sizeof(vst));
		vst[x][y]=1;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&Cpass[nx][ny]){
				if(!vst[nx][ny]){
					vst[nx][ny]=1;
					ans++;
				}
				x=nx,y=ny;
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
