#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1009;
char ch[N][N];
bool ok[N][N];
ll cx[4]={0,1,0,-1};
ll cy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ll T;
	ll n,m,k,x,y,d,cnt=1,nx=0,ny=0;
	cin>>T;
	while(T--){
		cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=m;++j)
				cin>>ch[i][j];
		ok[x][y]=1;
		for(ll i=1;i<=k;++i){
			nx=x+cx[d],ny=y+cy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&ch[nx][ny]=='.'){
				x=nx,y=ny;
				if(!ok[x][y]){
					ok[x][y]=1;
					cnt++;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=m;++j)
				ok[i][j]=0;
	}
	return 0;
}
