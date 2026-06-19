#include<iostream>
#include<algorithm> 
using namespace std;
const int MAXN=1e5+5;
const double eps=1e-6;
int n,m,l,v;
int p[MAXN];
int cd[MAXN],cv[MAXN],ca[MAXN];
int tot;
pair<double,double> b[MAXN];
int ans1,ans2;
void solve(){
	tot=0;
	ans1=0;
	ans2=0;
	scanf("%d %d %d %d",&n,&m,&l,&v);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&cd[i],&cv[i],&ca[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	double maxx=0;
	for(int i=1;i<=n;i++){
		if(ca[i]==0){
			if(cv[i]>v){
				if(lower_bound(p+1,p+1+m,cd[i])==(p+1+m)){
//					printf("###%d\n",i);
					ans1++;
					continue;
				}
				maxx=max(maxx,(double)cd[i]);
			}else{
//				printf("###%d\n",i);
				ans1++;
			}
		}else if(ca[i]>0){
			if(cv[i]>v){
				if(lower_bound(p+1,p+1+m,cd[i])==(p+1+m)){
//					printf("###%d\n",i);
					ans1++;
					continue;
				}
				maxx=max(maxx,(double)cd[i]);
			}else{
				double wh=cd[i]+(1.0*v*v-1.0*cv[i]*cv[i])/(2.0*ca[i]);
//				printf("%d %lf\n",i,wh);
				if(wh>=l||upper_bound(p+1,p+1+m,wh)==(p+1+m)){
//					printf("###%d\n",i);
					ans1++;
					continue;
				}
				maxx=max(maxx,wh);
			}
		}else{
			if(cv[i]>v){
				double wh=cd[i]+(1.0*v*v-1.0*cv[i]*cv[i])/(2.0*ca[i]);
				int w=lower_bound(p+1,p+1+m,cd[i])-p;
//				printf("%lf %d %d\n",wh,w,cd[i]);
				if(p[w]>=wh){
//					printf("###%d\n",i);
					ans1++;
					continue;
				}
				if(wh<=l){
					b[++tot].first=wh;
					b[tot].second=cd[i];
				}else{
					maxx=max(maxx,(double)cd[i]);
				} 
			}else{
//				printf("###%d\n",i);
				ans1++;
			}
		}
	}
	sort(b+1,b+1+tot);
	int cnt=0;
	bool flag;
//	for(int i=1;i<=tot;i++){
//		printf("%d %lf %lf\n",i,b[i].first,b[i].second);
//	}
	int maxb=-1;
	for(int i=1;i<=tot;i++){
		if(maxb<b[i].second){
			int w=lower_bound(p+1,p+1+m,b[i].first)-p-1;
			maxb=max(maxb,p[w]);
//			printf("###%d\n",maxb);
			ans2++;
		}
	}
//	printf("%d %lf\n",maxb,maxx);
	if(maxx!=0&&maxb<maxx){
		ans2++;
	}
	printf("%d %d\n",n-ans1,m-ans2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
