#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,b[1005][1005],ans,f[1005][1005];
int x,y,d;
string s;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t>0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=0;
			}
		}
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		f[x][y]=1;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				if(s[j]=='x') b[i][j]=2;
				else b[i][j]=1;
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(b[x][y+1]==1&&x!=0&&y+1!=0&&x<=n&&y+1<=m){
					y=y+1;
					if(f[x][y]==0) ans++;
					f[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}else if(d==1){
				if(b[x+1][y]==1&&x+1!=0&&y!=0&&x+1<=n&&y<=m){
					x=x+1;
					if(f[x][y]==0){
						ans++;
						f[x][y]=1;
					} 
				}else{
					d=(d+1)%4;
				}
			}else if(d==2){
				if(b[x][y-1]==1&&x!=0&&y-1!=0&&x<=n&&y-1<=m){
					y=y-1;
					if(f[x][y]==0) ans++;
					f[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}else{
				if(b[x-1][y]==1&&x-1!=0&&y!=0&&x-1<=n&&y<=m){
					x=x-1;
					if(f[x][y]==0) ans++;
					f[x][y]=1;
				}else{
					d=(d+1)%4;
				}
			}
		}
		cout<<ans<<endl;
		t--;	
	}
	return 0;
}
