#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	int to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	while(T--){
		char a[1010][1010];
		bool b[1010][1010];
		memset(b,0,sizeof(b)); 
		int n,m,k,x,y,d,ans=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		b[x][y]=1;
		while(k--){
			if(x+to[d][0]<=0 || x+to[d][0]>n || y+to[d][1]<=0 || y+to[d][1]>m || a[x+to[d][0]][y+to[d][1]]=='x'){
				d=(d+1)%4;
			}else{
				x=x+to[d][0];
				y=y+to[d][1];
				if(!b[x][y]) ans++;
				b[x][y]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
