#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,tmp,a[100005];
int d[100005],v1[100005],ac[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&tmp);
	while(tmp--){
		int ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &d[i],&v1[i],&ac[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d", &a[i]);
		}
		sort(a+1,a+m+1);
		for(int i=1;i<=n;i++){
			if(v1[i]>v&&d[i]<=a[m]){
				ans++;
			}
		}
		printf("%d %d\n",ans,m-1);
	}
	return 0;
} 
