#include<bits/stdc++.h> 
using namespace std;
long long t,n,m,k,x,y,d,xx,yy,s,a[1005][1005];
char b;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		s=0,xx=0,yy=0;
		memset(a,true,sizeof(a));
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>b;
				if(b=='.'){
					a[i][j]=1;
				}else{
					a[i][j]=0;
				}
			}
		}
		a[x][y]=2;
		for(int i=1;i<=k;i++){
			if(d==0){
				xx=x,yy=y+1;
			}else if(d==1){
				xx=x+1,yy=y;
			}else if(d==2){
				xx=x,yy=y-1;
			}else if(d==3){
				xx=x-1,yy=y;
			}
			if(1<=xx and xx<=n and 1<=yy and yy<=m and a[xx][yy]!=0){
				x=xx,y=yy;
				a[x][y]=2;
			}else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==2){
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
