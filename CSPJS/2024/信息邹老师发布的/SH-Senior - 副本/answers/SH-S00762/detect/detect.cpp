#include <bits/stdc++.h>
using namespace std;
struct node{
	double x,v,a,vm;
	int l=0,r=0;
}car[100005];
double maxx=0;
double xx;
int t=0,n,m,tmpx,tmpv,cnt;
bool nec=0;
bool cmp(double x,double y){
	return x<y;
}
bool cmp2(int x,int y){
	return car[x].l<car[x].r;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	double l=0,vmax=0,x,v,a;
	int ans1=0,ans2=0;
	scanf("%d",&t);
	while(t--){
		maxx=0;
		scanf("%d%d%lf%lf",&n,&m,&l,&vmax);
		vmax=vmax*vmax;
		ans1=0,ans2=0,nec=0;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf",&car[i].x,&car[i].v,&car[i].a);
			car[i].v*=car[i].v;
		}
		for(int i=1;i<=m;i++){
			scanf("%lf",&xx);
			maxx=max(xx,maxx);
		}
		for(int i=1;i<=n;i++){
			if(car[i].x>maxx){
				continue;
			}
			if(car[i].a>0) {
				car[i].vm=2*car[i].a*(maxx-car[i].x)+car[i].v;
				if(car[i].vm>vmax){
					nec=1;
					ans1++;
				}
			}
			else if(car[i].a==0){
				car[i].vm=car[i].v;
				if(car[i].vm>vmax){
					nec=1;
					ans1++;
				}
			}
			
		}
		ans2=m;
		if(nec) ans2--;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
} 

