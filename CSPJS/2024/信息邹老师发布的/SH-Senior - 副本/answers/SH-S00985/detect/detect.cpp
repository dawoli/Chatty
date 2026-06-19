#include<bits/stdc++.h>
const int N=100002;
int T,n,m,d[N],p[N],ans1,ans2,x;
long long L,V,v[N],a[N];
struct cars{
	int l,r;
	bool ok=0;
	bool operator<(const cars x)const{
		return l!=x.l?l<x.l:r>x.r;
	}
}car[N];
bool isA(){
	for(int i=0;i<n;i++)if(a[i])return 0;
	return 1;
}
void A(){
	for(int i=0;i<n;i++)
		if(v[i]>V&&d[i]<=p[m-1])ans1++;
	if(ans1)ans2--;
}
void f(){
		x=-1;
		for(int i=0;i<n;i++){
			if(a[i]>0)
				if(v[i]>V)car[i].l=d[i],car[i].r=L;
				else{
					car[i].l=(V*V-v[i]*v[i])/(a[i]<<1)+d[i]+1;
					if(car[i].l>L)car[i].ok=1;
					else car[i].r=L;
				}
			else if(a[i])
				if(v[i]<=V)car[i].ok=1;
				else{
					car[i].l=d[i],car[i].r=ceil(((long double)(V*V-v[i]*v[i]))/(a[i]<<1))+d[i]-1;
					if(car[i].r>L)car[i].r=L;
				}
			else 
				if(v[i]<=V)car[i].ok=1;
				else car[i].l=d[i],car[i].r=L;
			if(!car[i].ok){
				car[i].l=std::lower_bound(p,p+m,car[i].l)-p,car[i].r=std::upper_bound(p,p+m,car[i].r)-p-1;
				if(car[i].l>car[i].r)car[i].ok=1;
			}
		}
		std::sort(car,car+n);
		for(int i=0;i<n;i++){
			if(car[i].ok)continue;
			ans1++;
			int j=i-1;
			while(j>=0&&car[j].ok)j--;
			while(j>=0&&car[j].r>=car[i].r){
				car[j].ok=1;
				while(j>=0&&car[j].ok)j--;
			}
		}
		for(int i=0;i<n;i++)
			if(!car[i].ok&&car[i].l>x)x=car[i].r,ans2--;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%lld%lld",&n,&m,&L,&V);
		for(int i=0;i<n;i++)scanf("%d%lld%lld",d+i,v+i,a+i);
		for(int i=0;i<m;i++)scanf("%d",p+i);
		memset(car,0,sizeof(car));
		ans1=0,ans2=m;
		if(isA())A();
		else f();
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
