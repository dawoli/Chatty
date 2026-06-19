#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1005][1005]={0};
int vis[1005][1005]={0};
int cnt=0;
int n,m;
int explore(int x,int y,int d,int k){//当前x，y，方向，步数 
	if(vis[x][y]==0){
		vis[x][y]=1;
		cnt++;
	}
	if(k==0){
		return 0;
	}
	if(d==0){
		y+=1;
		if(x>=1 and y>=1 and x<=n and y<=m and a[x][y]==0){
			explore(x,y,d,--k);
		}else{
			explore(x,y-1,1,--k);
		}
	}
	else if(d==1){
		x+=1;
		if(x>=1 and y>=1 and x<=n and y<=m and a[x][y]==0){
			explore(x,y,d,--k);
		}else{
			explore(x-1,y,2,--k);
		}
	}
	else if(d==2){
		y-=1;
		if(x>=1 and y>=1 and x<=n and y<=m and a[x][y]==0){
			explore(x,y,d,--k);
		}else{
			explore(x,y+1,3,--k);
		}
	}
	else if(d==3){
		x-=1;
		if(x>=1 and y>=1 and x<=n and y<=m and a[x][y]==0){
			explore(x,y,d,--k);
		}else{
			explore(x+1,y,0,--k);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int z=1;z<=T;z++){
		cnt=0;
		int k,x,y,d;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		char in[n+5][1005]={'0'};
		for(int i=1;i<=n;i++){
			cin>>in[i];
			for(int j=1;j<=m;j++){
				vis[i][j]=0;
				if(in[i][j-1]=='.')a[i][j]=0; //0空地 
				if(in[i][j-1]=='x')a[i][j]=1; //1臭 
			}
		}
		explore(x,y,d,k);
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
