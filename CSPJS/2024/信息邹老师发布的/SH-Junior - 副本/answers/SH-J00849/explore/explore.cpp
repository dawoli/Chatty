#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool ok[1009][1009],vst[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		char c;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			cin>>c;
			ok[i][j]=(c=='.');
			vst[i][j]=0;
		}
		cnt=1;
		vst[x][y]=1;
		for(int i=1,nxtx,nxty;i<=k;i++){
			nxtx=x+dx[d];
			nxty=y+dy[d];
			//cout<<nxtx<<' '<<nxty<<ok[nxtx][nxty]<<"|";
			if(nxtx<1||nxty<1||nxtx>n||nxty>m||!ok[nxtx][nxty]) d=(d+1)%4;
			else{
				x=nxtx;
				y=nxty;
				if(!vst[x][y]){
					vst[x][y]=1;
					cnt++;
				}
			}
			//cout<<x<<y<<d<<endl;
		}
		cout<<cnt<<endl;
	} 
	return 0;
}

