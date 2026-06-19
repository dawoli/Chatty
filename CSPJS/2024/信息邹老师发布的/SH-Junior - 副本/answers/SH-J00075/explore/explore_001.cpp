#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,k,x,y,d,ny,nx,ans;
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
char a[1005][1005];
bool b[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n>>m>>k>>x >> y >> d;
		memset(b,0,sizeof(b));
		b[x][y]=1;
		for (ll i=1;i<=n;i++) for (ll j=1;j<=m;j++) cin >> a[i][j];
		while(k--){
			nx=x+dx[d];
			ny=y+dy[d];
			if (nx<=n&&ny<=m&&nx>=1&&ny>=1&&a[nx][ny]=='.'){
				x=nx;
				y=ny;
				b[nx][ny]=1;
			}
			else{
				d++;
				d%=4;
				continue;
			}
		}
		ans=0;
		for (ll i=1;i<=n;i++){
			for (ll j=1;j<=m;j++){
				if (b[i][j]){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
