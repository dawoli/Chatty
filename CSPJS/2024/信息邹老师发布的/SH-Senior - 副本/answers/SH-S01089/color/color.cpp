#include<bits/stdc++.h>
using namespace std;
const int N=5005;

int n,a[N],sum[N];
int f[N][N],g[N];

int s(int l,int r){
	return sum[r]-sum[l-1]-(a[l]==a[l-1])*a[l];
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++) scanf("%d",&a[i]);
		for(int i=1; i<=n; i++) sum[i]=sum[i-1]+(a[i]==a[i-1])*a[i];
		
		memset(g,0,sizeof g);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++){
				f[i][j]=g[j-1]+s(j,i);
				g[i]=max(g[i],f[i][j]+(a[i+1]==a[j-1])*a[i+1]);
			}
		
		int res=0;
		for(int i=1; i<=n; i++) res=max(res,f[n][i]);
		printf("%d\n",res);
	}
	return 0;
}
