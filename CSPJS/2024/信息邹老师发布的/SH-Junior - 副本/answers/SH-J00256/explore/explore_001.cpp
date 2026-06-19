#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,s,step,xx,yy;
char ex[1005][1005];
bool v[1005][1005];
int main() {
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  cin>>t;
  while (t--) {
    cin>>n>>m>>k>>x>>y>>d;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++) cin>>ex[i][j];
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++) v[i][j]=0;
    step=1;v[x][y]=1;
    for (int i=1;i<=k;i++) {
      if (d==3) xx=x-1,yy=y;
      if (d==2) xx=x,yy=y-1;
      if (d==1) xx=x+1,yy=y;
      if (d==0) xx=x,yy=y+1;      
      if (xx<1 || xx>n || yy<1 || yy>m || ex[xx][yy]=='x') d=(d+1)%4; 
      else {
        x=xx,y=yy;
        if (v[x][y]==0) step++,v[x][y]=1;
      }
    }
    cout<<step<<endl;
  }
  return 0;
}
