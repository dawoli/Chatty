#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,sx,sy,d,ans;
char c[1005][1005];
bool vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	  cin>>n>>m>>k;
	  cin>>sx>>sy>>d;
	  for(int i=1;i<=n;i++){
	  	for(int j=1;j<=m;j++){
		  cin>>c[i][j];
		  vis[i][j]=false;
		}
	  }
	  ans=0;
	  int curx=sx,cury=sy;
	  vis[curx][cury]=true,ans++;
	  for(int i=1;i<=k;i++){
	  	int nxtx=curx,nxty=cury;
	  	if(d==0) nxty++;
	  	else if(d==1) nxtx++;
	  	else if(d==2) nxty--;
	  	else if(d==3) nxtx--;
	  	if((nxtx>=1&&nxtx<=n)&&(nxty>=1&&nxty<=m)&&c[nxtx][nxty]!='x'){
	  	  if(!vis[nxtx][nxty]){
	  	  	vis[nxtx][nxty]=true,ans++;
		  }
		  curx=nxtx,cury=nxty;
		}
		else{
		  d=(d+1)%4;
		}
	  }
	  cout<<ans<<endl;
	}
	return 0;
}
