#include<bits/stdc++.h>
using namespace std;
int n,m,k0,x0,y0,d0,ans=0;
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
char map1[10000][10000];
int map2[10000][10000];
int dfs(int x,int y,int d,int k){
    if(map1[x][y]=='.'){
    	ans++;
	}
	while(k0-k>0){
		if(map1[x+fx[d]][y+fy[d]]=='.'){
			dfs(x+fx[d],y+fy[d],d,k+1);
			break;
		}else{
			d=(d+1)%4;
			k++;
		}
	}
	return 0;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int a;
    cin>>a;
    while(a--){
    	cin>>n>>m>>k0>>x0>>y0>>d0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			cin>>map1[i][j];
			}
		}
    	dfs(x0,y0,d0,0);
    	cout<<ans<<endl;
    	ans=-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
