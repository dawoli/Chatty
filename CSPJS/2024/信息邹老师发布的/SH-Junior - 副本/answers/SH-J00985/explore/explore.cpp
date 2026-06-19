#include<bits/stdc++.h>
using namespace std;
int t,ans;
char a[1007][1007];
bool b[1007][1007];
int n,m,k,x,y,d;
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			b[i][j]=0;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&x,&y,&d);
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>a[j][l];
			}
		}
		b[x][y]=t;
		for(int j=1;j<=k;j++){
			if (d==0){
				if (a[x][y+1]=='.'&&y+1<=m){
					y++;
					b[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if (d==1){
				if (a[x+1][y]=='.'&&x+1<=n){
					x++;
					b[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if (d==2){
				if (a[x][y-1]=='.'&&y-1>0){
					y--;
					b[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if (d==3){
				if (a[x-1][y]=='.'&&x-1>0){
					x--;
					b[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				if (b[j][l]==1) ans++;
			}
		}
		printf("%d\n",ans);
		init();
	}
	return 0;
}
