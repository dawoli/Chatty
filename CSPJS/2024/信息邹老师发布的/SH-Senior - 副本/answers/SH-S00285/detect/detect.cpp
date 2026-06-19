#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,L,V;
int d[100005],v[100005],a[100005],p[100005],w[100005];//w存放超速车辆开始位置 
//int calc_start(int x){//计算超速区间起点 
//	if(a[x]<=0){//速度在下降 
//		if(v[x]<=V){
//			return L;//没有超速过 
//		}else{
//			return d[x];
//		}
//	}else{
//		if(v[x]<=V){
//			return min(L,d[x]+(V*V-v[x]*v[x])/(2*a[x])+1); 
//		}else{
//			return d[x];
//		}
//		return d[x]; 
//	}
//}
//int calc_end(int x){//计算终点  
//	if(a[x]>=0){//速度在上升 
//		if(((V*V-v[x]*v[x])/(2*a[x])+1)>=L){
//			return L;//没有超速过 
//		}else{
//			return min(L,d[x]+(V*V-v[x]*v[x])/(2*a[x])+1);
//		}
//	}else{
//		if(v[x]<=V){
//			return d[x];
//		}else{
//			return min(L,d[x]+(v[x]*v[x]-V*V)/(2*a[x]));
//		}
//	}
//}
//double calc(int x,int y){//第x辆车经过第y个测速仪 
//	int dist=p[y]-d[x];
//	 
//}
void solve(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&d[i],&v[i],&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	int farest_p=-1;
	for(int i=1;i<=m;i++){
		if(p[i]>farest_p){
			farest_p=p[i];
		}
	}
	int res1=0;
	for(int i=1;i<=n;i++){//遍历车 
		if(v[i]>V && d[i]<=farest_p){
			res1++;
			w[res1]=d[i]; 
		}
	}
	int min=L+1;
	for(int i=1;i<=res1;i++){
		if(w[i]<min){
			min=w[i];
		}
	}
	int res2=m;
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++){
		if(p[i]<min){
			res2--;
		}else{
			break;
		}
	}
	printf("%d %d\n",res1,res2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve();
	}
	fclose(stdin);fclose(stdout);
}
