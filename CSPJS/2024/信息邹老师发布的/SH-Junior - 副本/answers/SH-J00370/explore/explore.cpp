#include<bits/stdc++.h>
#define ll int
using namespace std;
short T;
char mp[1009][1009];
bool vst[1008][1008];
int main(){
    freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%hd",&T);
	while(T--){
        ll n,m,k,x,y;
        short d;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %hd",&x,&y,&d);
        memset(mp,'x',sizeof(mp));
        memset(vst,0,sizeof(vst));
        for(int i=1;i<=n;i++) {
            scanf("%s\n",mp[i]+1);
        }
        for(int i=1;i<=k;i++) {
            vst[x][y]=true;
            if(d==0) {
                if(mp[x][y+1]=='.') y++;
                else d++;
            } else if(d==1) {
                if(mp[x+1][y]=='.') x++;
                else d++;
            } else if(d==2) {
                if(mp[x][y-1]=='.') y--;
                else d++;
            } else if(d==3) {
                if(mp[x-1][y]=='.') x--;
                else d=0;
            }
        }
        vst[x][y]=true;
        ll ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans+=vst[i][j];
        printf("%d\n",ans);
	}
	return 0;
}
