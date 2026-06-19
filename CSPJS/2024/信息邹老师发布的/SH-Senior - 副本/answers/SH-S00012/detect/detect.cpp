#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+5,M=1e6+5;

struct node{
	int d,v,a;
	int s,t;
	bool speed;
}car[N];

int t,n,m,l,v,p[N],val[M<<2],init_val[M];

void push_up(int rt) {val[rt]=val[rt*2]+val[rt*2+1];}

void build(int rt,int l,int r) {
	if(l==r) val[rt]=init_val[l];
	else {
		int mid=(l+r)>>1;
		build(rt*2,l,mid);
		build(rt*2+1,mid+1,r); 
		push_up(rt);
	}
}

void add(int rt,int l,int r,int pos,int x) {
	if(l==r&&l==pos) {
		val[pos]=x;
		return;
	}
	int mid=(l+r)>>1;
	add(rt*2,l,mid,pos,x);
	add(rt*2+1,mid+1,r,pos,x);
	push_up(rt);
	return;
}

int query(int rt,int l,int r,int ql,int qr) {
	if(ql>r||qr<l) return 0;
	if(ql<=l&&r<=qr) {
		return val[rt];
	}
	int mid=(l+r)>>1;
	return query(rt*2,l,mid,ql,qr)+query(rt*2+1,mid+1,r,ql,qr);
}

bool cmp(node a,node b) {
	if(a.speed!=b.speed) return a.speed<b.speed;
	if(a.s==b.s) return a.t<b.t;
	return a.s<b.s;
} 

signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(val,0,sizeof(val));
		memset(init_val,0,sizeof(init_val));
		memset(car,0,sizeof(car));
		scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
		for(int i=1;i<=n;i++) {
			car[i].speed=0;
			scanf("%lld%lld%lld",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].v>v) car[i].s=car[i].d;
			else if(car[i].a<=0) car[i].s=-1;
			else {
				if((v*v-car[i].v*car[i].v)%(2*car[i].a)==0) car[i].s=car[i].d+(v*v-car[i].v*car[i].v)/(2*car[i].a)+1;
				else car[i].s=car[i].d+(v*v-car[i].v*car[i].v)/(2*car[i].a);
			}
			if(car[i].a>=0) car[i].t=l;
			else {
				if((-v*v+car[i].v*car[i].v)%(-2*car[i].a)==0) car[i].t=car[i].d+(-v*v+car[i].v*car[i].v)/(-2*car[i].a)-1;
				else car[i].t=min(car[i].d+(-v*v+car[i].v*car[i].v)/(-2*car[i].a),l);
			}
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld",&p[i]);
			init_val[p[i]]++;
		}
		build(1,1,l);
		int ans=0;
		for(int i=1;i<=n;i++) {
			if(car[i].s==-1) continue;
			if(car[i].s>l) continue;
			if(car[i].s>car[i].t) continue; 
			int temp=query(1,1,l,car[i].s,car[i].t);
			if(temp>0) ans++,car[i].speed=1;
		}
		sort(car+1,car+n+1,cmp);
		int mergeds=0,mergedt=0,merged=0,ans2=1,cnt=0;
		for(int i=1;i<=n;i++) {
			if(!car[i-1].speed||!car[i].speed) continue;
			//cout<<car[i].s<<' '<<car[i].t<<" "<<mergeds<<" "<<mergedt<<'\n';
			if(mergeds==0) cnt++;
			if(merged==0) {
				if(max(car[i].s,car[i-1].s)<=min(car[i].t,car[i-1].t)&&query(1,1,l,car[i].s,min(car[i-1].t,car[i].t))>0) {
					merged=1;
					mergeds=max(car[i].s,car[i].s);mergedt=min(car[i-1].t,car[i].t);
				}else mergeds=mergedt=merged=0,ans2++;
			}else {
				if(max(mergeds,car[i].s)<=min(mergedt,car[i].t)&&query(1,1,l,max(mergeds,car[i].s),min(mergedt,car[i].t))>0) {
					merged=1;
					mergeds=max(mergeds,car[i].s);mergedt=min(mergedt,car[i].t);
				}else mergeds=mergedt=merged=0,ans2++;
			}
			//cout<<i<<' '<<mergeds<<' '<<mergedt<<'\n';
		}
		if(ans==0) ans2=0;
		cout<<ans<<' '<<m-ans2<<'\n';
	}
	return 0;
} 
