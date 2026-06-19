#include<bits/stdc++.h>
using namespace std;
int t,n,ans,m,k,x,y,d,dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
char f[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		ans=1;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		--x;
		--y;
		for(int j=0;j<n;++j)
			scanf("%s",f[j]);
		f[x][y]='F';
		for(int j=0;j<k;++j){
			if(0<=x+dx[d]&&x+dx[d]<n&&0<=y+dy[d]&&y+dy[d]<m&&f[x+dx[d]][y+dy[d]]!='x'){
				x=x+dx[d];
				y=y+dy[d];
				if(f[x][y]!='F')
					++ans;
				f[x][y]='F';
			}else if(d==3)
				d=0;
			else
				++d;
		}
		printf("%d\n",ans);
	}
	return 0;
}
