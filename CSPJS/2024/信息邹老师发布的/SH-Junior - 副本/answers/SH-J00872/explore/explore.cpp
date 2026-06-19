#include<bits/stdc++.h>
using namespace std;
int t,sum;
int n,m,k;
int x,y,d;
bool sc_maze[1010][1010],ans[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		n=m=k=x=y=d=sum=0;
		memset(sc_maze,false,sizeof(sc_maze));
		memset(ans,false,sizeof(ans));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans[x][y]=1;
		char a;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a;
				if(a=='.')sc_maze[i][j]=1;
			}
		}
		int dx=0,dy=0,dd=0;
		for(int i=1;i<=k;i++){
			if(d==0){
				dx=x,dy=y+1;
				if(sc_maze[dx][dy]&&dx<=n&&dx>=1&&dy<=m&&dy>=1){
					x=dx,y=dy;
					ans[x][y]=1;
				}
				else{
					dd=(d+1)%4;
					d=dd;
				}
			}
			else if(d==1){
				dx=x+1,dy=y;
				if(sc_maze[dx][dy]&&dx<=n&&dx>=1&&dy<=m&&dy>=1){
					x=dx,y=dy;
					ans[x][y]=1;
				}
				else{
					dd=(d+1)%4;
					d=dd;
				}
			}
			else if(d==2){
				dx=x,dy=y-1;
				if(sc_maze[dx][dy]&&dx<=n&&dx>=1&&dy<=m&&dy>=1){
					x=dx,y=dy;
					ans[x][y]=1;
				}
				else{
					dd=(d+1)%4;
					d=dd;
				}
			}
			else if(d==3){
				dx=x-1,dy=y;
				if(sc_maze[dx][dy]&&dx<=n&&dx>=1&&dy<=m&&dy>=1){
					x=dx,y=dy;
					ans[x][y]=1;
				}
				else{
					dd=(d+1)%4;
					d=dd;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ans[i][j])sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
