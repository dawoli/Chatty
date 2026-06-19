#include<cstdio>
using namespace std;
const int N=1010; char c[N][N]; bool vis[N][N];
void solve() {
  int n,m,k,bx,by,bd; scanf("%d %d %d %d %d %d",&n,&m,&k,&bx,&by,&bd),vis[bx][by]=true;
  for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
  while(k--) {
  	int x=bx,y=by;
    if(bd==0) y++;
    if(bd==1) x++;
    if(bd==2) y--;
    if(bd==3) x--;
    if(x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]=='.') vis[x][y]=true,bx=x,by=y;
    else bd=(bd+1)%4;
  }
  int cnt=0;
  for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]) cnt++,vis[i][j]=false;
  printf("%d\n",cnt);
}
int main() {
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  int t; scanf("%d",&t);
  while(t--) solve();
  return 0;
}
