#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
ll T,n,m,k,x,y,dir,a[1005][1005],vst[1005][1005],ans;
char ch;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		fill(vst[0],vst[0]+1005*1005,0);
		cin>>n>>m>>k>>x>>y>>dir;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				cin>>ch;
				a[i][j]=(ch=='x');
			}
		}
		ans=1;
		vst[x][y]=1;
		//cout<<x<<" "<<y<<endl;
		for(ll i=1;i<=k;i++){
			ll dx=x+d[dir][0];
			ll dy=y+d[dir][1];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!a[dx][dy]){
				if(!vst[dx][dy]){
					vst[dx][dy]=1;
					//cout<<dx<<" "<<dy<<endl;
					ans++;
				}
				x=dx;
				y=dy;
			}
			else{
				dir=(dir+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

