#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,m,n,k,x,y,d,ans=0;
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		ans=1;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(y+1>m||a[x][y+1]=='x'){
					d=(d+3)%4;
				}else{
					y+=1;
					if(b[x][y]==0){
						ans++;
						b[x][y]=1;
					}
				}
			}else if(d==1){
				if(x-1<1||a[x-1][y]=='x'){
					d=(d+3)%4;
				}else{
					x-=1;
					if(b[x][y]==0){
						ans++;
						b[x][y]=1;
					}
				}
			}else if(d==2){
				if(y-1<1||a[x][y-1]=='x'){
					d=(d+3)%4;
				}else{
					y-=1;
					if(b[x][y]==0){
						ans++;
						b[x][y]=1;
					}
				}
			}else{
				if(x+1>n||a[x+1][y]=='x'){
					d=(d+3)%4;
				}else{
					x+=1;
					if(b[x][y]==0){
						ans++;
						b[x][y]=1;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
