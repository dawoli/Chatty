#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,dd[1010][1010],xx,yy,cnt;
char s[1010][1010];
void f1(int &xxx,int &yyy,int ddd){
	if(ddd==0){
		yyy++;
	}
	if(ddd==1){
		xxx++;
	}
	if(ddd==2){
		yyy--;
	}
	if(ddd==3){
		xxx--;
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		memset(dd,0,sizeof(dd));
		scanf("%d %d %d\n%d %d %d",&n,&m,&k,&x,&y,&d);
		for(int j=1;j<=n;++j){
			scanf("%s",s[j]+1);
		}
		dd[x][y]=1;
		for(int j=1;j<=k;++j){
			xx=x;
			yy=y;
			f1(xx,yy,d);
			if(xx<1||xx>n||yy<1||yy>m){
				d=(d+1)%4;
				continue;
			}
			if(s[xx][yy]=='x'){
				d=(d+1)%4;
				continue;
			}
			dd[xx][yy]=1;
			x=xx;
			y=yy;
		}
		cnt=0;
		for(int j=1;j<=n;++j){
			for(int jj=1;jj<=m;++jj){
				cnt+=dd[j][jj];
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
