#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,vis[1005][1005],x,y,d,xx,yy,ans=0;
char mp[1005][1005];
int main(){
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
    cin>>t;
    while(t--){
    	cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			vis[i][j]=0;
    			cin>>mp[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			vis[x][y]=1;
			//下一步位置 
			if(d==0){
				xx=x;yy=y+1;
			}
			else if(d==1){
				xx=x+1;yy=y;
			}
			else if(d==2){
				xx=x;yy=y-1;
			}
			else{
				xx=x-1;yy=y-1;
			}
			//判断位置
			if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[x][y]=='.'){
				x=xx;y=yy;
				vis[x][y]=1;
			}else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])ans++;
			}
		}
		cout<<ans<<endl;
	}
    
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
