#include<bits/stdc++.h>
using namespace std;
char mapp[1005][1005];
bool judge[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n,m,k;
	int x0,y0,d,cnt;
	string s;
	for(int ti=0;ti<t;ti++){
		memset(judge,0,sizeof(judge));
		cnt=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x0,&y0,&d);
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				mapp[i][j]=s[j-1];
			}
		}
		judge[x0][y0]=1;
		int xp,yp;
		for(int i=0;i<k;i++){
			xp=x0;
			yp=y0;
			if(d==0) yp++;
			else if(d==1) xp++;
			else if(d==2) yp--;
			else if(d==3) xp--;
			if(1<=xp && xp<=n && 1<=yp && yp<=m && mapp[xp][yp]!='x'){
				x0=xp;
				y0=yp;
				judge[x0][y0]=1;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(judge[i][j]) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
