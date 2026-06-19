#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool b[1010][1010];
int xy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T; cin>>T;
	for(int x=1;x<=T;x++){
		memset(b,0,sizeof(b));
		int k,xfir,yfir,ans=1;
		int n,m,d;
		cin>>n>>m>>k>>xfir>>yfir>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>a[i][j];
		}
		b[xfir][yfir]=1;
		while(k>0){
			int tx=xfir+xy[d][0],ty=yfir+xy[d][1];
			while((a[tx][ty]=='x'||tx<1||tx>n||ty<1||ty>m)&&k>0){
				d++;
				d%=4;
				tx=xfir+xy[d][0],ty=yfir+xy[d][1];
				k--;
			}
			if(k<=0) break; 
			if(!b[tx][ty]){
				ans++;
				b[tx][ty]=1;
			}
			xfir=tx,yfir=ty;
			k--;
		}
		cout<<ans<<endl;
	}
	return 0;
}

