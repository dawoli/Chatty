#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1009;
int dx[5]={0,1,0,-1};
int dy[5]={1,0,-1,0};
ll n,m,k;
ll pX,pY,d; 
ll nX,nY;
char c[N][N];
bool vst[N][N];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>pX>>pY>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>c[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vst[i][j]=0;
		vst[pX][pY]=1;
		for(int i=1;i<=k;i++){
			nX=pX+dx[d],nY=pY+dy[d];
			if(nX>=1&&nX<=n&&nY>=1&&nY<=m&&c[nX][nY]=='.')
				pX=nX,pY=nY;
			else d=(d+1)%4;
			vst[pX][pY]=1;
		}
		ll cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(vst[i][j])
					cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
