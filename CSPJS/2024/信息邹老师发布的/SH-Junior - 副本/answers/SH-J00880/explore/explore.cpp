#include<iostream>
#include<cstdio>
int main(){
    freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	std::cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,k,x,y,d;
		std::cin>>n>>m>>k>>x>>y>>d;
		char a[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
			    std::cin>>a[i][j];
		}
		int ans=0;
		if(d==0){
			if(a[x][y+1]=='.'&&x<=n&&y+1<=m&&x>=1&&y>=1)ans++;
			} 
		if(d==1){
			if(a[x+1][y]=='.'&&x+1<=n&&y<=m&&x>=1&&y>=1)ans++;
			} 
		if(d==2){
			if(a[x][y-1]=='.'&&x<=n&&y-1<=m&&x>=1&&y>=1)ans++;
			} 
		if(d==3){
			if(a[x-1][y]=='.'&&x-1<=n&&y<=m&&x>=1&&y>=1)ans++;
			} 
		std::cout<<ans<<std::endl;
	}
}
