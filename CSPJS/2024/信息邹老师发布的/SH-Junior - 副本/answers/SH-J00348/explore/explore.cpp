#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t;
int n,m,k;
char a[N][N];
int x,y,d;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool step[N][N];
int main(){
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	memset(step,false,sizeof(step));
    	cin>>n>>m>>k;
    	cin>>x>>y>>d;
    	step[x][y]=true;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			int xx=x+dx[d];
			int yy=y+dy[d];
			bool tur=false;
			if(xx<1 || xx>n) tur=true;
			if(yy<1 || yy>m) tur=true;
			if(a[xx][yy]=='x') tur=true;
			if(tur) d=(d+1)%4;
			else{
				x=xx;
				y=yy;
				step[x][y]=true;
			}
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(step[i][j])ans++;
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}

