#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char map1[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		int ans=1;
		int maxans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map1[i][j];
				if(map1[i][j]=='.')maxans++;
			}
		}
		map1[x][y]='#';
		while(k--){
			x+=dx[d];
			y+=dy[d];
			if(x<1||x>n||y<1||y>m||map1[x][y]=='x'){
				x-=dx[d];
				y-=dy[d];
				d=(d+1)%4;
				continue;
			}
			if(map1[x][y]=='.'){
				ans++;
				map1[x][y]='#';
			}
			if(ans==maxans)break;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
