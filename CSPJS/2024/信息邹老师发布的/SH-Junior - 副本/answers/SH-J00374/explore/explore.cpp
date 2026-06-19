#include<bits/stdc++.h>
using namespace std;
int T;int n,m,k,r,c,d,ans=0;char mat[1010][1010];
int dr[5]={0,1,0,-1},dc[5]={1,0,-1,0};
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>k;
		cin>>r>>c>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mat[i][j];
			}
		}mat[r][c]='#';
		for(int i=1;i<=k;i++){
			int tr=r+dr[d];
			int tc=c+dc[d];
			if(tr>=1&&tr<=n&&tc>=1&&tc<=m&&(mat[tr][tc]=='.'||mat[tr][tc]=='#')){
				r=tr;c=tc;mat[tr][tc]='#';
			}else d=(d+1)%4;
		}for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mat[i][j]=='#')ans++;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
