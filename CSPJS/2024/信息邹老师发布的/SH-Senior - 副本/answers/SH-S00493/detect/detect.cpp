#include<bits/stdc++.h> 
using namespace std;
int n,m,l,v;
struct car{
	int d,v,a;
	int l,r;
}a[100005];
struct rng{
	int l,r,valid;
}b[100005];
int p[100005];
void solve(){
	scanf("%d%d%d%d",&n,&m,&l,&v);
	for(int i = 1;i<=n;i++){
		scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
		if(a[i].a==0){
			if(a[i].v>v) a[i].l=a[i].d,a[i].r=l;
			else a[i].l=l,a[i].r=1;
		}else if(a[i].a>0){
			if(a[i].v>v){
				a[i].l=a[i].d,a[i].r=l;
				continue;
			}
			int dis=(v*v-a[i].v*a[i].v)/(2*a[i].a)+1; 
			//if((v*v-a[i].v*a[i].v)%(2*a[i].a)) dis++;
			a[i].l=a[i].d+dis;
			a[i].r=l;
		}else{
			if(a[i].v<=v){
				a[i].l=l,a[i].r=1;continue;
			}
			int dis=(v*v-a[i].v*a[i].v)/(2*a[i].a);
			if((a[i].v*a[i].v-v*v)%(2*(-a[i].a))==0) dis--;
			a[i].l=a[i].d;
			a[i].r=a[i].d+dis;
		}
	}
	for(int i = 1;i<=m;i++) scanf("%d",&p[i]);
	int ans=0;
	for(int i = 1;i<=n;i++){
		int ll=lower_bound(p+1,p+m+1,a[i].l)-p;
		int rr=lower_bound(p+1,p+m+1,a[i].r)-p;
		if(p[rr]>a[i].r||rr>m) rr--;
		b[i].l=ll;b[i].r=rr;
		//cout<<a[i].l<<" "<<a[i].r<<" "<<ll<<" "<<rr<<endl;
		if(ll<=rr){
			ans++;b[i].valid=1;
		}else{
			b[i].valid=0;
		}
	}
	sort(b+1,b+n+1,[](rng x,rng y){
		return x.l<y.l;
	});
	//for(int i = 1;i<=n;i++) cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].valid<<endl;
	int ll=1,rr=l,sum=0,flag=0;
	for(int i = 1;i<=n;i++){
		if(!b[i].valid) continue;
		flag=1;
		ll=max(b[i].l,ll);
		rr=min(b[i].r,rr);
		if(ll>rr){
			sum++;
			ll=b[i].l,rr=b[i].r;
		}
	}
	if(ll<=rr&&flag) sum++;
	printf("%d %d\n",ans,m-sum);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
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
