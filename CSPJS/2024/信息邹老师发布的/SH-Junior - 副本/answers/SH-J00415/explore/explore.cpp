#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN=1010;
const ll dx[5]={0,1,0,-1};
const ll dy[5]={1,0,-1,0};
ll T,n,m,k,x,y,md,ans;
char a[MaxN][MaxN];
bitset<MaxN>vys[MaxN];
bitset<MaxN>vis[4][MaxN];
int main(){
	ll mx,my;
	//*/
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	//*/
	scanf("%lld",&T);
	while(T-->0){
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld%lld%lld",&x,&y,&md);
		for(ll i=1;i<=n;i++){
			scanf("%s",a[i]+1);
			a[i][m+1]='x';
			vys[i].reset();
			for(ll j=0;j<4;j++)
				vis[j][i].reset();
		}
		for(ll i=1;i<=m;i++)
			a[n+1][i]='x';
		ans=1;
		vys[x][y]=1;
		while(k-->0){
			if(vis[md][x][y])
				break;
			else
				vis[md][x][y]=1;
			mx=x+dx[md];
			my=y+dy[md];
			if(a[mx][my]=='.'){
				x=mx;y=my;
			}else{
				md=(md+1)%4;
			}
			if(!vys[x][y]){
				vys[x][y]=1;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
