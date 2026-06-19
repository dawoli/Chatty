#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
char mmap[N][N];
bool vst[N][N];
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll T,n,m,k,x,y,d,cnt;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++)
				cin>>mmap[i][j];
		for(ll i=1;i<=n;i++) 
			for(ll j=1;j<=m;j++) 
				vst[i][j]=0;
		vst[x][y]=1;
		cnt=1;
		for(ll i=1;i<=k;i++){
			ll nx=x+dx[d];
			ll ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mmap[nx][ny]=='.'){
				if(vst[nx][ny]==0) vst[nx][ny]=1,cnt++;
				x=nx,y=ny;
			}
			else{
				d=(d+1)%4;
			}
//			cout<<T<<' '<<i<<' '<<x<<' '<<y<<' '<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
