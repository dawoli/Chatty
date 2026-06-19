#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int t,n,m,k,d,sx,sy,sum;
char a[maxn][maxn];
bool vis[maxn][maxn];
inline bool pd(int x,int y){
	if(a[x][y]=='x'||x<1||x>n||y<1||y>m){
		return 0;
	}
	return 1;
}
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		sum=1;
		memset(vis,0,sizeof(vis));
		vis[sx][sy]=1;
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(register int i=1;i<=k;i++){
			if(d==0){
				if(pd(sx,sy+1)){
					sy+=1;
					if(!vis[sx][sy]){
						sum++;
						vis[sx][sy]=1;
					}
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(pd(sx+1,sy)){
					sx+=1;
					if(!vis[sx][sy]){
						sum++;
						vis[sx][sy]=1;
					}
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(pd(sx,sy-1)){
					sy-=1;
					if(!vis[sx][sy]){
						sum++;
						vis[sx][sy]=1;
					}
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==3){
				if(pd(sx-1,sy)){
					sx-=1;
					if(!vis[sx][sy]){
						sum++;
						vis[sx][sy]=1;
					}
				}
				else{
					d=(d+1)%4;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
