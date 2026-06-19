#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,d,t,c[4][2]={0,1,1,0,0,-1,-1,0},st[1010][1010],ans;
char s[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&a,&b,&d),memset(st,0,sizeof(st)),ans=0,st[a][b]=1;
		for(int w=1;w<=n;w++)scanf("%s",s[w]+1);
		for(int w=1;w<=k;w++){
			int i=a+c[d][0],j=b+c[d][1];
			if(i>=1&&i<=n&&j>=1&&j<=m&&s[i][j]!='x')a=i,b=j;
			else d++,d%=4;
			st[a][b]=1;
		}
		for(int w=1;w<=n;w++)for(int x=1;x<=m;x++)if(st[w][x])ans++;
		printf("%d\n",ans);
	}
	return 0;
}
