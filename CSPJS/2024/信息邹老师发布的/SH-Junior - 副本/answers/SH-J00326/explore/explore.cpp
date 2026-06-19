#include<bits/stdc++.h>
using namespace std;
const int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
int t;
int n,m,k;
int X0,Y0,d0;
char ex[1005][1005];
bool used[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(used,0,sizeof(used));
		cin>>n>>m>>k;
		cin>>X0>>Y0>>d0;
		int ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ex[i][j];
			}
		}
		used[X0][Y0]=1;
		for(int i=1;i<=k;i++){
			int x1=X0+dx[d0],y1=Y0+dy[d0];
			if(x1>=1 && x1<=n && y1>=1 && y1<=m && ex[x1][y1]=='.'){
				X0=x1,Y0=y1;
				if(!used[x1][y1])ans++;
				used[x1][y1]=1;
			}
			else{
				d0=(d0+1)%4;
			}
			//cout<<X0<<" "<<Y0<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
