#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int T,n,a[N],c[N],col[3],ans,j,k,f[5009][5009],ff[5009][5009];
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		col[1]=0;
		col[2]=0;
		for(int i=1;i<=n;i++){
			if(col[c[i]]==0){
				col[c[i]]=i;
				continue;
			}
			if(a[col[c[i]]]==a[i]) cnt+=a[i];
			col[c[i]]=i;
		}
		ans=max(ans,cnt);
		return;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=2;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n<=15) dfs(1);
		else{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					f[i][j]=0;
					ff[i][j]=0;
				}
			for(int i=1;i<=n;i++){ 
				j=i-1;
				for(k=1;k<=i-2;k++){
					if(a[j]==a[i]) f[i][k]=max(f[i][k],f[j][k]+a[i]);
					else f[i][k]=max(f[i][k],f[j][k]);
				}
				k=i-1;
				for(j=1;j<=i-2;j++){
					if(a[j]==a[i]) f[i][k]=max(f[i][k],ff[k][j]+a[i]);
					else f[i][k]=max(f[i][k],f[k][j]);
				}
				j=i-1;
				for(k=1;k<=i-2;k++){
					if(a[k]==a[i]) ff[i][j]=max(ff[i][j],f[j][k]+a[i]);
					else ff[i][j]=max(ff[i][j],f[j][k]);
				}
				k=i-1;
				for(j=1;j<=i-2;j++){
					if(a[k]==a[i]) ff[i][j]=max(ff[i][j],ff[k][j]+a[i]);
					else ff[i][j]=max(ff[i][j],ff[k][j]);
				}
			}
			for(int i=1;i<=n-1;i++) ans=max(ans,f[n][i]);
			for(int i=1;i<=n-1;i++) ans=max(ans,ff[n][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
