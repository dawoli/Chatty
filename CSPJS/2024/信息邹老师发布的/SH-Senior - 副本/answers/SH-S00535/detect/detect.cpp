#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,m,L,V;
int d[N],v[N],a[N],p[N];
int sum[N],ans,cnt;
vector<int> car[N],dev[N];
bool vis[N],visdev[N];
struct division{
	int fz;
	int fm;
};
void input(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&d[i],&v[i],&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	sort(p+1,p+m+1);
}
int efl(division comp){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(p[mid]*comp.fm>=comp.fz)
			r=mid-1;
		else
			l=mid;
	}
	return l;
}
int efr(division comp){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(p[mid]*comp.fm<=comp.fz)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
void add(int l,int r,int i){
	if(l>r){
		vis[i]=1;
		return;
	}
	for(int j=l;j<=r;j++){
		car[j].push_back(i);
		dev[i].push_back(j);
		sum[j]++;
	}
//	printf("%d %d %d %d\n",l,r,i,ans);
	ans++;
}
void detect(){
	division l,r;
	for(int i=1;i<=n;i++){
		if(a[i]<=0 && v[i]<=V){
			vis[i]=1;
			continue;
		}
		if(a[i]==0){
			l.fm=1;
			l.fz=d[i];
			r.fm=1;
			r.fz=L+1;
			add(efr(l),efl(r),i);
//			printf("%d %d %d\n",efr(l),efl(r),i);
		}
		else if(a[i]<0){
			l.fm=1;
			l.fz=d[i]-1;
			r.fm=-2*a[i];
			r.fz=v[i]*v[i]-V*V+d[i]*(-2*a[i]);
			add(efr(l),efl(r),i);
//			printf("%d %d %d\n",efr(l),efl(r),i);
		}
		else{
			if(v[i]>=V){
				l.fm=1;
				l.fz=d[i];
			}
			else{
				l.fm=2*a[i];
				l.fz=V*V-v[i]*v[i]+d[i]*(2*a[i]);
			}
			r.fm=1;
			r.fz=L+1;
			add(efr(l),efl(r),i);
//			printf("%d %d %d\n",efr(l),efl(r),i);
		}
	}
}
void count(){
	int maxn,id;
	bool f;
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<car[i].size();j++) 
//			printf("%d ",car[i][j]);
//		printf(":%d\n",i);
//	}
	for(int i=1;i<=n;i++){
//		if(i==6)
//			printf("%d\n",id);
		maxn=0;
		f=0;
		if(vis[i]) continue;
		for(int j=0;j<dev[i].size();j++){
			if(visdev[dev[i][j]]) continue;
			if(maxn<sum[dev[i][j]]){
				maxn=sum[dev[i][j]];
				id=dev[i][j];
				f=1;
			}
		}
		if(!f) continue;
		visdev[id]=1;
		for(int j=0;j<car[id].size();j++){
			if(vis[car[id][j]]) continue;
			vis[car[id][j]]=1;
			for(int k=0;k<dev[car[id][j]].size();k++)
				sum[dev[car[id][j]][k]]--;
		}
		cnt++;
//		if(i==6)
//			printf("%d\n",id);
	}
}
void init(){
	memset(car,0,sizeof(car));
	memset(dev,0,sizeof(dev));
	memset(sum,0,sizeof(sum));
	memset(vis,0,sizeof(vis));
	memset(visdev,0,sizeof(visdev));
	ans=0; cnt=0;
}
void output(int i){
	printf("%d %d",ans,m-cnt);
	if(i!=T) printf("\n"); 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		init();
		input();
		detect();
		count();
		output(i);
	}
	return 0;
}

