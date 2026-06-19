#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1009;
const ll dx[4]={0,1,0,-1};
const ll dy[4]={1,0,-1,0};
ll t,n,m,k,x,y,d,ans=0;
char a[N][N];
bool v[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=m;j++){
				cin>>a[i][j];
				v[i][j]=0;
			}
		ans=1;
		v[x][y]=1;
		for(ll i=1;i<=k;i++){
			ll nx=x+dx[d],ny=y+dy[d];
			if(nx>n||nx<1||ny<1||ny>m)
				d=(d+1)%4;
			else if(a[nx][ny]!='.')
				d=(d+1)%4;
			else{
				x=nx;
				y=ny;
				if(!v[x][y]){
					ans++;
					v[x][y]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
