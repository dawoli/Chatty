#include<algorithm>
#include<cstring>
#include<utility>
#include<cstdio>
#include<cmath>
using namespace std;
typedef pair<int,int> PII;
const int N=100010;
const long double eps=1e-7;
int _,n,m,len,lim,idx,idx_,cnt;
int p[N],chosen[N];
PII inter[N],inter_[N];
inline int cmp(long double a,long double b){
	if(fabs(a-b)<eps)
		return 0;
	if(a>b)
		return 1;
	return -1;
}
struct Car{
	int d,v,a,st,ed;
	bool over_speed;
	Car(int d_=0,int v_=0,int a_=0){
		d=d_;	v=v_;	a=a_;	return;
	}
	inline void calc(){
		if(!a){
			if(v<=lim){
				over_speed=false;
				st=m+1;
				ed=m;
				return;
			}
			st=lower_bound(p+1,p+m+1,d)-p;
			ed=m;
			over_speed=(st<=ed);
			return;
		}
		long double s_=((long double)lim*lim-v*v)/(2.0*a);
		if(a>0){
			int s=s_+1;
			while(cmp(s,s_)==1)
				s--;
			st=max(lower_bound(p+1,p+m+1,d)-p,upper_bound(p+1,p+m+1,d+s)-p);
			ed=m;
		}
		else{
			int s=s_;
			while(cmp(s,s_)==-1)
				s++;
			st=lower_bound(p+1,p+m+1,d)-p;
			ed=lower_bound(p+1,p+m+1,d+s)-p-1;
		}
		over_speed=(st<=ed);
		return;
	}
};
Car c[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&_);
	while(_--){
		idx=0;
		idx_=0;
		cnt=0;
		scanf("%d%d%d%d",&n,&m,&len,&lim);
		for(int i=1;i<=n;i++){
			int d,v,a;
			scanf("%d%d%d",&d,&v,&a);
			c[i]=Car(d,v,a);
		}
		for(int i=1;i<=m;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			c[i].calc();
			if(c[i].over_speed)
				inter[++idx]=PII(c[i].st,c[i].ed);
		}
		printf("%d ",idx);
		sort(inter+1,inter+idx+1,[](const PII &a,const PII &b){
			if(a.second!=b.second)
				return a.second<b.second;
			return a.first>b.first;
		});
		for(int i=1;i<=idx;i++){
			if(i==1){
				inter_[++idx_]=inter[i];
				continue;
			}
			if(inter[i-1].second==inter[i].second)
				continue;
			inter_[++idx_]=inter[i];
		}
		memcpy(inter,inter_,sizeof inter);
		idx=idx_;
		for(int i=1;i<=idx;i++){
			int l=inter[i].first,r=inter[i].second;
			int last=chosen[cnt];
			if((l<=last)&&(last<=r))
				continue;
			chosen[++cnt]=r;
		}
		printf("%d\n",m-cnt);
	}
	return 0;
}
