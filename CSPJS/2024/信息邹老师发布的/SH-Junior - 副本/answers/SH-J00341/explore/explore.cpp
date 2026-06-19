#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
bool a[3005][3005],b[3005][3005];
char c;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=0;
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			c=getchar();
			for(int j=1;j<=m;j++){
				c=getchar();
				if(c=='x'){
					a[i][j]=1;
				}
			}
		}
		for(int i=1;i<=k;i++){
			b[x][y]=1;
			if(d==0&&y!=m&&!a[x][y+1]){
				y++;
				d=0;
			}
			else if(d==1&&x!=n&&!a[x+1][y]){
				x++;
				d=1;
			}
			else if(d==2&&y!=1&&!a[x][y-1]){
				y--;
				d=2;
			}
			else if(d==3&&x!=1&&!a[x-1][y]){
				x--;
				d=3;
			}
			else{
				d++;
				d%=4;
			}
		}
		b[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j])ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
