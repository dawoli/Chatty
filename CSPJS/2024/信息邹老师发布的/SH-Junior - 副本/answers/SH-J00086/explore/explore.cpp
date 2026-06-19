#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 dx[4]={0,1,0,-1};
i64 dy[4]={1,0,-1,0};

int main(){
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	char map[1010][1010];
	i64 T;
	cin>>T;
	for(i64 var=1;var<=T;var++){
		i64 n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(i64 i=1;i<=n;i++){
			for(i64 j=1;j<=m;j++){
				cin>>map[i][j];
			}
		}
		for(i64 i=1;i<=k;i++){
			map[x][y]='*';
			if(map[x+dx[d]][y+dy[d]]=='x'||x+dx[d]<1||y+dy[d]<1||x+dx[d]>n||y+dy[d]>m){
				d=(d+1)%4;
			}else{
				x+=dx[d];
				y+=dx[d];
				
			}
			cout<<"x="<<x<<" y="<<y<<" d="<<d<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j]=='*'){
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
	
	return 0;
}
