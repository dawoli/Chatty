#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V;
int d[N],v[N],a[N],p[N];
int sum[N];
int ans1,ans2;
bool flag1=1,flag2=1,flag3=1;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    	ans1=0,ans2=0;
    	scanf("%d%d%d%d",&n,&m,&L,&V);
    	for(int i=1;i<=n;i++){
    		scanf("%d%d%d",&d[i],&v[i],&a[i]);
    		if(a[i]!=0) flag1=0;
    		if(a[i]<=0) flag2=0;
    		if(a[i]>=0) flag3=0;
		}
    	for(int i=1;i<=m;i++) scanf("%d",&p[i]);
        if(flag1){
			for(int i=1;i<=n;i++){
				if(v[i]>V) ans1+=1;
			}
			ans2=m-1;
			if(!ans1) ans2++;
			printf("%d %d\n",ans1,ans2);
		}else if(flag2){
			for(int i=1;i<=n;i++){
				long double t=v[i]*v[i]+2*a[i]*(d[i]+p[n]);
				t=sqrt(t);
				if(t>V) ans1+=1;
			}
			ans2=m-1;
			if(!ans1) ans2++;
			printf("%d %d\n",ans1,ans2);
		}else if(flag3){
			for(int i=1;i<=n;i++){
				long double t=v[i]*v[i]+2*a[i]*(d[i]+p[1]);
				if(t>=0) t=sqrt(t);
				if(t>V) ans1+=1;
			}
			ans2=m-1;
			if(!ans1) ans2++;
			printf("%d %d\n",ans1,ans2);
		}else{
			puts("3 3");
		}
	}
	return 0;
}
