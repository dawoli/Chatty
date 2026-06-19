#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int T;
struct node{
	int d,v,a;
};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		
		int n,m,l,v;
		node car[MAXN];
		int p[MAXN];
		bool is[MAXN]={0};
		scanf("%d%d%d%d",&n,&m,&l,&v);
		long long ansa=0,ansb=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&car[i].d,&car[i].v,&car[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		
		for(int i=1;i<=n;i++){
			
			if(car[i].a>0&&car[i].v<v){//Vcar < Vlimit , Vadd>0
				double t=(v-car[i].v)*1.0/car[i].a;
				double s=car[i].v*t+car[i].a/2.0*t*t;
				if(car[i].d*1.0+s<=l*1.0){
					int pos=ceil(car[i].d*1.0+s);
					int l=1;
					for( ;l<=m;l++){
						if(p[l]>=pos)break;
					}
					if(p[l]>=pos){
						ansa++;
						is[l]=true;	
					}
				}
			}
			
			else if(car[i].v>v&&car[i].a>=0){//Vcar > Vlimit , Vadd>=0
				int pos=car[i].d;
				int l=1,r=m;
				for( ;l<=m;l++){
					if(p[l]>=pos)break;
				}
				if(p[l]>=pos){
					ansa++;
					is[l]=true;
				}
			}
			else if(car[i].v>v&&car[i].a<0){//Vcar > Vlimit , Vadd<0
				double t=(v-car[i].v)*1.0/car[i].a;
				double s=car[i].v*t+car[i].a/2.0*t*t;
				if(car[i].d*1.0+s<=l*1.0){
					int pos=ceil(car[i].d*1.0+s);
					int l=1,r=m;
					for( ;l<=m;l++){
						if(p[l]<=pos&&p[l]>=car[i].d)break;
					}
					if(p[l]<=pos&&p[l]>=car[i].d){
						ansa++;
						is[l]=true;
					}
				}
			}
		}
		printf("%lld ",ansa);
		
		for(int i=1;i<=m;i++){
			if(is[i])ansb++;
		}
		printf("%lld\n",m-ansb);
	}
	return 0;
}
