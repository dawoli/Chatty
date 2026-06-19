#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,v,flag,flag1,ret,vis[100010],p[100010],d[100010],c[100010],a[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		flag=0,flag1=0,ret=0;
		scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i],&c[i],&a[i]);
			if(a[i]!=0){
				flag=1;
			}if(a[i]<=0){
				flag1=1;
			}
		}for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
		}if(flag==0){
			for(int i=1;i<=n;i++){
				if(c[i]>v&&d[i]<=p[m]){
					ret++;
				}
			}printf("%d",ret);
			if(ret==0){
				printf(" %d\n",m);
			}else{
				printf(" %d\n",m-1);
			}
		}else if(flag1==0){
			long double dy=(long double)1.0*v;
			for(int i=1;i<=n;i++){
				if(d[i]<=p[m]&&sqrt((long double)((long double)1.0*c[i]*c[i]+(long double)2.0*a[i]*(p[m]-d[i])))>dy){
					ret++;
				}
			}printf("%d",ret);
			if(ret==0){
				printf(" %d\n",m);
			}else{
				printf(" %d\n",m-1);
			}
		}
	}return 0;
}
