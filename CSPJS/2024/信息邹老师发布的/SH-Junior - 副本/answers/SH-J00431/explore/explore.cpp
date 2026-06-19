#include<bits/stdc++.h>
using namespace std;

int t,n,m,k,x,y,d,to_x,to_y,ans;
char c[1010][1010];
bool a[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=1;i<=1010;i++){
			for(int j=1;j<=1010;j++){
				a[i][j]=0;
			}
		}
		ans=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		while(k--){
			to_x=x+dx[d];
			to_y=y+dy[d];
			if(c[to_x][to_y]=='.'){
				x=to_x;
				y=to_y;
				if(!a[to_x][to_y]){
					ans++;
					a[to_x][to_y]=1;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
