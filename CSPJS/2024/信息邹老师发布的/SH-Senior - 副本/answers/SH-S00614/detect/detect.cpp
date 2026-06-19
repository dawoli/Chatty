#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d,v,a,p,op[100010],ps[100010],cnt,mxp,ans;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if(v>V)op[++cnt]=i,ps[cnt]=d,ans++;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p);
			mxp=max(mxp,p);
		}
		for(int i=1;i<=cnt;i++)
			if(ps[i]>mxp)ans--;
		printf("%d ",ans);
		if(ans)printf("%d\n",m-1);
		else printf("%d\n",m);
		memset(op,0,sizeof(op));
		memset(ps,0,sizeof(ps));
		cnt=mxp=ans=0;
	}
	return 0;
}
