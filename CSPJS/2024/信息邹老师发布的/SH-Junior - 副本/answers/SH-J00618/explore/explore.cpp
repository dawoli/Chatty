#include<iostream>
#include<cstdio>
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int a[1010][1010];
bool vis[1010][1010]={false};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	std::cin>>T;
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			a[i][j]=2;
	for(int t=1;t<=T;t++){
		int n,m,k;
		std::cin>>n>>m>>k;
		int x,y,d;
		std::cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c;
				std::cin>>c;
				if(c=='x')a[i][j]=1;
				else a[i][j]=0;
			}
		}
		long long ans=1;
		vis[x][y]=true;
		for(int i=1;i<=k;i++){
			if(a[x+dx[d]][y+dy[d]]!=0)d=(d+1)%4;
			else{
				x+=dx[d],y+=dy[d];
				if(!vis[x][y])ans++;
				vis[x][y]=true;
			}
		}
		std::cout<<ans<<"\n";
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=2,vis[i][j]=false;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
