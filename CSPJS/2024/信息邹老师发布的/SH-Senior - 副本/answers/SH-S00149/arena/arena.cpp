#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],c[100010];
int k;
int q[20];
int t;
int tp[300][5];
int ans;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=20;i++){
		if(1<<i>=n){
			k=i;
			break;
		}
	}
	for(int i=k;i>0;i--){
		scanf("%d",&q[i]);
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&tp[i][j]);
		}
	}
	for(int l=1;l<=t;l++){
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=a[i]^tp[l][i%4];
		}
		for(int i=1;i<=n;i++){
			int an=0;
			for(int j=1;j<=c[n];j++){
				an=an^a[j];
			}
			ans=ans^(i*an);
		}
		printf("%d\n",ans);
	}
}
