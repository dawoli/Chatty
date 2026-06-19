#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,len,lim,q,d[N],v[N],p[N],a[N];
struct node{
	int l,r;
	bool operator<(const node&x)const{
		return r!=x.r?r<x.r:l<x.l;
	}
}car[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&n,&m,&len,&lim);
		int cnt=0,ans=0;
		for(int i=1;i<=n;++i)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&p[i]);
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				int x=lower_bound(p+1,p+m+1,d[i])-p;
				if(v[i]>lim&&x<=m)car[++cnt]=(node){x,m};
			}
			else if(a[i]>0){
				int k;
				if(v[i]>lim)k=lower_bound(p+1,p+m+1,d[i])-p;
				else k=upper_bound(p+1,p+m+1,d[i]+(lim*lim-v[i]*v[i])/a[i]/2)-p;
				if(k<=m)car[++cnt]=(node){k,m};
			}
			else{
				if(v[i]<=lim)continue;
				int k=ceil(d[i]+(v[i]*v[i]-lim*lim)/(-2.0*a[i]));//find the first that <k
				int kk=lower_bound(p+1,p+m+1,k)-p-1;
				int x=lower_bound(p+1,p+m+1,d[i])-p;
				if(kk>=x)car[++cnt]=(node){x,kk};
			}
		}
		printf("%d ",cnt);
		sort(car+1,car+cnt+1);
		int now_min=-1;
		for(int i=1;i<=cnt;++i){//cout<<car[i].l<<' '<<car[i].r<<endl;
			if(now_min<car[i].l)++ans,now_min=car[i].r;//,cout<<ans<<endl;
		}
		printf("%d\n",m-ans);//cout<<"*\n";
	}
	return 0;
}
