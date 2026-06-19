#include <stdio.h>
#include <algorithm>
using namespace std;

int n,m,L,V;
int ans1,ans2,ans3;

struct car{
	int v,a;
	double pos,s,l,r;
	car(){s=-1;}
}a[100010];

double p[100010];

void work(int x){
	a[x].s=(double(V)*double(V) - double(a[x].v)*double(a[x].v)) / double(a[x].a)/2+a[x].pos;
}

void solve1(double a,double b){
	if(a>b) return;
	int l=1,r=m;
	while(l<=r){
		if(p[l]>a && p[l]<b) {
			ans1++;
			return;
		}
		if(p[r]>a && p[r]<b) {
			ans1++;
			return;
		}
		int mid=(l+r)>>1;
		if(p[mid]>a && p[mid]<b) {
			ans1++;
			return;
		}
		if(p[mid]<a)l=mid+1;
		else if(p[mid]>b) r=mid-1;
	}
	return;
}void solve2(double a,double b){
	if(a>b) return;
	int l=1,r=m;
	while(l<=r){
		if(p[l]>a && p[l]<b) {
			ans3++;
			return;
		}
		if(p[r]>a && p[r]<b) {
			ans3++;
			return;
		}
		int mid=(l+r)>>1;
		if(p[mid]>a && p[mid]<b) {
			ans3++;
			return;
		}
		if(p[mid]<a)l=mid+1;
		else if(p[mid]>b) r=mid-1;
	}
	return;
}

int main(){
	freopen("detect1.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ans1=0,ans2=0;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%lf%d%d", &a[i].pos, &a[i].v, &a[i].a);
		}
		for(int i=1;i<=m;i++){
			scanf("%lf",&p[i]);
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			if(a[i].a!=0)
				work(i);
			if(a[i].a==0) {
				if(a[i].v > V) {
					ans1++;
				}
				continue;
			}
			else if(a[i].a<0){
				a[i].l=a[i].pos,a[i].r=a[i].s;
				solve1(a[i].pos,a[i].s);
			}
			else{
				a[i].l=a[i].s,a[i].r=L;
				solve1(a[i].s,L);
			}
		}
//		for(int j=1;j<=m;j++){
//			int t=p[j];
//			p[j]=-1;
//			sort(p+1,p+m+1);
//			ans3=0;
//			for(int i=1;i<=n;i++){
//				if(a[i].a==0) {
//					if(a[i].v > V) {
//						ans3++;
//					}
//					continue;
//				}
//				else if(a[i].a<0){
//					a[i].l=a[i].pos,a[i].r=a[i].s;
//					solve2(a[i].pos,a[i].s);
//				}
//				else{
//					a[i].l=a[i].s,a[i].r=L;
//					solve2(a[i].s,L);
//				}
//			}
//			if(ans3==ans1)ans2++;
//			else {
//				p[j]=t;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			printf("%lf ",a[i].s);
//		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
