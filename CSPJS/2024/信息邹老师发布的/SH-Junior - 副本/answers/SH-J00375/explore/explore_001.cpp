#include<bits/stdc++.h>
using namespace std;

int v[1005][1005];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int u=1;u<=T;u++){
		char f[1005][1005];
		int n,m,k,ans=1;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>y>>x>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>f[i][j];
			}
		}
		v[y][x]=1;
		for(int i=1;i<=k;i++){
			int a=x+dx[d],b=y+dy[d];
			if(a>=1 && a<=m && b>=1 && b<=n && f[b][a]!='x'){
				x=a;
				y=b;
				if(v[y][x]==0){
					ans++;
					v[y][x]=1;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				v[i][j]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
