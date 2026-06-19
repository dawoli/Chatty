#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x0,y0,d0,ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int forest[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t>0){
		cin>>n>>m>>k;
		memset(forest,0,sizeof(forest));
		ans=0;
		cin>>x0>>y0>>d0;
		forest[x0][y0]=1;
		for(int i=1;i<=n;i++){
			char s[1010];
			cin>>s;
			for(int j=1;j<=m;j++)
				if(s[j-1]=='x')forest[i][j]=-1;
		}
		for(int i=0;i<k;i++)
			if(x0+dx[d0]>=1&&x0+dx[d0]<=n&&y0+dy[d0]>=1&&y0+dy[d0]<=m&&forest[x0+dx[d0]][y0+dy[d0]]!=-1){
				x0+=dx[d0];
				y0+=dy[d0];
				forest[x0][y0]=1;
			}
			else
				d0=(d0+1)%4;
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=m;j++)
				if(forest[i][j]==1)ans++;
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
