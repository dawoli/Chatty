#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
int a[1005][1005],b[1005][1005];//a为地图数组 b为记录是否走过的数组 
char k1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for (int l=1;l<=t;l++){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		b[x][y]=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>k1;
				if (k1=='x') a[i][j]=1;
				else a[i][j]=0;
			}
		}//输入，空地为0障碍为1 
		for (int i=1;i<=k;i++){
			if (d==0){
				if (a[x][y+1]==0 && y+1<=m){
					y++;
					b[x][y]++;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			if (d==1){
				if (a[x+1][y]==0 && x+1<=n){
					x++;
					b[x][y]++;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			if (d==2){
				if (a[x][y-1]==0 && y-1>=1){
					y--;
					b[x][y]++;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			if (d==3){
				if (a[x-1][y]==0 && x-1>=1){
					x--;
					b[x][y]++;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
		}//操作
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				a[i][j]=0;
				if (b[i][j]!=0){
					ans++;
					b[i][j]=0;
				}
			}
		}//答案+初始化 
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
