#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll p[N],tr[N],l;
double v;
int T,n,m,k;
bool r[N*10];
int sr[N*10];
bool f,f2;
double s;
struct node{
	ll d;
	ll a,v;
}c[N];
struct n2{
	ll l,r;
}q[N];
//int lowbit(int x){
//	return x&-x;
//}
//void add(int x,int c){
//	for(int i=x;i<=n;i+=lowbit(i)){
//		tr[i]+=c;
//	}
//}
//int query(int x){
//	int ans=0;
//	for(int i=x;i>0;i-=lowbit(i)){
//		ans+=tr[i];
//	}
//	return ans;
//}
int v1(double x){
	if(x!=int(x)) return floor(x);
	return x-1;
}
int v2(double x){
	if(x!=int(x)) return floor(x)+1;
	return x+1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%lld%lf",&n,&m,&l,&v);
		memset(r,0,sizeof(r));
		memset(sr,0,sizeof(sr));
		k=0;
		f=0;f2=0;
		for(int i=1;i<=n;i++){
			scanf("%d%lld%lld",&c[i].d,&c[i].v,&c[i].a);
			if(c[i].a!=0) f=1;
			if(c[i].a<=0) f2=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
			r[p[i]]=1;
		}
		sr[0]=r[0];
		for(int i=1;i<=l;i++){
			sr[i]=sr[i-1]+r[i];
		}
		if(f==0){
			for(int i=1;i<=n;i++){
				if(c[i].v>v&&sr[l]-sr[c[i].d-1]>0) k++;
			}
			if(k==0) printf("0 %lld\n",m);
			else printf("%d %lld\n",k,m-1);
			continue;
		}
		if(f2==0){
			for(int i=1;i<=n;i++){
				s=(v*v-c[i].v*c[i].v)/2.0/c[i].a;
				if(c[i].v>v){
					if(sr[l]-sr[c[i].d-1]>0) k++;
				}else{
					if(sr[l]-sr[c[i].d+v2(s)-1]>0&&c[i].d+v2(s)<=l) k++;
				}
			}
			if(k==0) printf("0 %lld\n",m);
			else printf("%d %lld\n",k,m-1);
			continue;			
		}
//		for(int i=1;i<=n;i++){
//			if(c[i].a==0){
//				if(c[i].v>v&&sr[l]-sr[c[i].d-1]>0) q[++k]={c[i].d,l};
//				continue;
//			}
//			s=(v*v-c[i].v*c[i].v)/2.0/c[i].a;
//			if(c[i].v>v){
//				if(c[i].a<0&&sr[c[i].d+v1(s)]-sr[c[i].d-1]>0) q[++k]={c[i].d,v1(s)};
//				else if(sr[l]-sr[c[i].d-1]>0) q[++k]={c[i].d,l};
//			}else{
//				if(c[i].a>0&&sr[l]-sr[c[i].d+v2(s)-1]>0) q[++k]={c[i].d+v2(s),l};
//			}
//			cout<<s<<" "<<k<<endl;
//		}
//		printf("%d---\n",k);
	}
	return 0;
}

