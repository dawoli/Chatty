#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int t,n,m,L,V,p[maxn],ans1,ans2,cnt,mid;
inline long long now_v(int d,int v,int a,int now_d){
	return v*v+2*a*(now_d-d);
}
inline bool cmp(int x,int y){
	return x<y;
}
struct CAR{
	int d,v,a;
}car[maxn];
struct segment{
	int l,r;
}line[maxn];
bool cmp2(segment a,segment b){
	return a.r<b.r;
}
void pre(){
	cnt=0;
	for(int i=0;i<n;i++){
		int l=0,r=m-1;bool bj=false;
		int side=lower_bound(p,p+m,car[i].d)-p;
		r=m-1;CAR c=car[i];long long ceild=(long long)V*V;
		if(side>m-1) continue;
		if(car[i].a<0){
			if(now_v(c.d,c.v,c.a,p[side])>ceild){
				while(l<r){
					mid=(l+r+1)>>1;
					if(now_v(c.d,c.v,c.a,p[mid])>ceild) l=mid;
					else r=mid-1;	
				}
				ans1++,bj=true;
				line[cnt].l=side;line[cnt++].r=l;
			}
		}
		else if(car[i].a>0){
			if(now_v(c.d,c.v,c.a,p[m-1])>ceild){
				while(l<r){
					mid=(l+r)>>1;
					if(now_v(c.d,c.v,c.a,p[mid])>ceild) r=mid;
					else l=mid+1;
				}
				ans1++,bj=true;
				line[cnt].l=l;line[cnt++].r=m-1;
			}
		}
		else if(car[i].v>V){
			ans1++;bj=true;
			line[cnt].l=side;line[cnt++].r=m-1;
		}
	}
}
void solve(){
	sort(line,line+cnt,cmp2);
	int tail=0,pre;
	while(tail<cnt){
		ans2++;pre=tail;
		while(line[tail].l<=line[pre].r) tail++;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		ans1=ans2=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int j=0;j<n;j++){
			scanf("%d %d %d",&car[j].d,&car[j].v,&car[j].a);
		}
		for(int j=0;j<m;j++){
			scanf("%d",&p[j]);
		}
		pre();solve();
		printf("%d %d\n",ans1,m-ans2);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
