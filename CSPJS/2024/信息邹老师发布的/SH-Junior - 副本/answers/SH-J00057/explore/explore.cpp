#include<iostream>
using namespace std;
bool vis[10010][10010];
char ma[10010][100010];
int tx[4]={0,1,0,-1};
int ty[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out",",w",stdout);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
		cout<<351<<endl;
		int n,m,k,x,y,d,ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		while(k>0){
			int jx=x+tx[d];
			int jy=y+ty[d];
			if(jx<=0 || jx>n || jy<=0 || jy>m || ma[jx][jy]=='x'){
				d=(++d)%4;
			}
			else{
				x=jx;
				y=jy;
				if(!vis[x][y]){
					vis[x][y]==true;
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
