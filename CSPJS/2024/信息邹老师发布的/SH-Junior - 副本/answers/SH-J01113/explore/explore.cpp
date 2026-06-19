#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int x00,y00,d00;
int x11,y11;
char a[1005][1005];
bool ans[1005][1005];
bool t00d00=1;
int test;
int move(){
	if(d==0) y11++;
	else if(d==1)x11++;
	else if(d==2) y11--;
	else x11--;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int times=0;times<t;times++){
		int sum=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x00,&y00,&d00);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans[i][j]=0;
				a[i][j]='\0';
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		x=x00,y=y00,d=d00;
		ans[x][y]=1;
		test++;
		for(int it=0;it<k;it++){
			x11=x,y11=y;
			move();
			if(a[x11][y11]=='.'){
				x=x11;y=y11;
				if(ans[x][y]==0) test++;
				ans[x][y]=1;
			}else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(ans[i][j]) sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
