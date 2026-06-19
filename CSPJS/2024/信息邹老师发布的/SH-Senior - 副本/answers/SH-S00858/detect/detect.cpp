#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9,L=1e6+9;
const double eps=0.000001;
int n,m,l,v,ans1,ans2,t,p[N];
struct afjpw{
	int d,v,a;
	double l,r;
};
bool check(afjpw a){
	if(2*a.a*(l-a.d)+a.v*a.v<0) return 0;
	double vt=sqrt(2*a.a*(l-a.d)+a.v*a.v);
	return ((vt-a.v)/a.a)>=0;
}
bool check_c(afjpw a,int w){
	return v*v>=2*a.a*(w-a.d)+a.v*a.v;
}
void get_lr(afjpw &u){
	if(u.a==0){
		if(u.v<=v){
			u.l=u.r=-1;
		} 
		else{
			u.l=double(u.d)-eps,u.r=double(l)+eps;	
		}
		return;
	}
	if(u.a<0){
		if(u.v<=v){
			u.l=u.r=-1;
			return;
		}
		u.l=double(u.d)-eps;
		if(check(u)==0){
			double t=double(double(v)-u.v)/double(u.a);
			u.r=double(u.d)+double(u.v)*t+0.5*double(u.a)*t*t+eps;
			return;
		} 
		else{
			if(check_c(u,l)==0) u.r=double(l)+eps;
			else{
				double t=double(double(v)-u.v)/double(u.a);
				u.r=double(u.d)+double(u.v)*t+0.5*double(u.a)*t*t+eps;
			}
		}
	}
	else{
		if(u.v*u.v+2*u.a*(l-u.d)<=v*v){
			u.l=u.r=-1;
			return;
		}
		double t=double(double(v)-u.v)/double(u.a);
		u.l=double(u.d)+double(u.v)*t+0.5*double(u.a)*t*t-eps;
		u.r=double(l)+eps;
	}
}
int get_rl(afjpw a){
	return int(a.l)+1;
}
int get_rr(afjpw a){
	return int(a.r);
}
afjpw c[N];
struct Node{
	int l,r;
};
int cnt;
Node cr[N];
bool cmp(Node a,Node b){
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
int sum[L],pre[L];
int bit[L];
int lowbit(int x){
	return x&(-x);
}
void change(int x,int ret){
	if(x==0) return;
	for(;x<=l;x+=lowbit(x)){
		bit[x]+=ret;
	} 
}
int query(int x){
	int rt=0;
	for(;x;x-=lowbit(x)){
		rt+=bit[x];
	} 
	return rt;
}
void init(){
	cnt=0;
	ans1=ans2=0;
	for(int i=1;i<=l;i++){
		sum[i]=bit[i]=pre[i]=0;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
			get_lr(c[i]);
		}
		for(int i=1;i<=n;i++){
			if(c[i].l<=-eps) continue;
			cnt++;
			cr[cnt].l=get_rl(c[i]);
			cr[cnt].r=get_rr(c[i]);
		}
		sort(cr+1,cr+1+cnt,cmp);
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			sum[p[i]]++;
		}
		for(int i=1;i<=l;i++) sum[i]+=sum[i-1];
		sort(p+1,p+1+m);
		for(int i=1;i<=cnt;i++){
			if(sum[cr[i].r]-sum[cr[i].l-1]>=1) ans1++;
		}
		for(int i=1;i<=m;i++) p[i]++;
		for(int i=1;i<=cnt;i++){
			cr[i].l++;
			cr[i].r++;
		}
		l++;
		for(int i=l;i>=1;i--) sum[i]=sum[i-1];
		sum[0]=0;
		for(int i=1;i<=l;i++){
			if(sum[i]-sum[i-1]>=1){
				pre[i]=i;
				continue;
			}
			pre[i]=pre[i-1];
		}
		for(int i=1;i<=cnt;i++){
			if(query(cr[i].r)-query(cr[i].l-1)>=1) continue;
			if(sum[cr[i].r]-sum[cr[i].l-1]==0) continue;
			change(pre[cr[i].r],1);
			ans2++;
		}
		printf("%d %d\n",ans1,m-ans2);
		init();
	}
	return 0;
}
