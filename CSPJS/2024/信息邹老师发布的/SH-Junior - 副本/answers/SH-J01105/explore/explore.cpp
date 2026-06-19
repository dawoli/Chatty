#include<bits/stdc++.h>
using namespace std;
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int t,n,m,k,posx,posy,posd;
bool a[1100][1100],f[1100][1100];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int T=0;T<t;T++){
		memset(f,false,sizeof(f));
		cin>>n>>m>>k;
		cin>>posx>>posy>>posd;
		char tmp;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>tmp;
				if(tmp=='x') a[i][j]=false;
				else a[i][j]=true;
			}
		}
		f[posx][posy]=true;
		for(int i=1;i<=k;i++){
			int tx = posx+d[posd][0];
			int ty = posy+d[posd][1];
			if(tx<1 or tx>n or ty<1 or ty>m) posd=(posd+1)%4;
			else if(a[tx][ty]){
				posx = tx;
				posy = ty;
				f[posx][posy] = true;
			}
			else posd=(posd+1)%4;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

