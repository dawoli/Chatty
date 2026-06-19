#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e6+10;
int T;
int n,m,L,v_max,p_sum[M];
int ma_del;
struct node{
	int v,a,d,dect;
}c[N];//初始速度，加速度,距离最南端位置 
int p[N];
bool flag=1;
int ans,cnt,ma=0,idx;
int get(int l,int r){
	return p_sum[r]-p_sum[l-1];
}
bool cmp(node x,node y){
	return x.d>y.d;
}
int main(){
	freopen("dect.in","r",stdin);
	freopen("dect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&v_max);
		for(int i=1;i<=n-1;i++){
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
			if(c[i].a!=0) flag=false;
			if(c[i].d>ma){
				ma=c[i].d;
				idx=i;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			p_sum[p[i]]++;
		}
		sort(c+1,c+1+n,cmp);
//		for(int i=1;i<=L;i++){
//			printf("%d ",p_sum[i]);
//		}
		for(int i=1;i<=L;i++){
			p_sum[i]=p_sum[i]+p_sum[i-1];
		}
		if(m==0){
			printf("0 0\n");
			return 0;
		}
		if(flag){
			for(int i=1;i<=n-1;i++){
				if(get(1,c[i].d)!=0&&get(c[i].d+1,L)==0){
					cnt++;
					c[i].dect=0;
					continue;
				}else{
					c[i].dect=1;
					continue;
				}
				if(c[i].v>v_max){
					ans++;
				}
			}
			for(int i=1;i<=n-1;i++){
				if(c[i].dect==1&&get(ma,L)>1){
					ma_del=get(ma,L)-1;
					break;
				}
			}
			printf("%d %d\n",ans,ma_del);
		}
	} 
	return 0;
}
