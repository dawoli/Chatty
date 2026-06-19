#include<bits/stdc++.h>
#define maxn 100010
#define ll long long int
using namespace std;
ll read(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll n,m,L,V,p[maxn];
struct car{ll d,v,a;}A[maxn];
void init(){
	n=read(), m=read(), L=read(), V=read();
	for(int i=1;i<=n;i++){
		A[i].d=read(), A[i].v=read(), A[i].a=read();
	}
	for(int i=1;i<=m;i++){
		p[i]=read();
	}
	return;
}
int ans1[maxn],ans2[maxn];
int k[maxn];
vector<int> S;
int solve1(){
	for(int i=1;i<=n;i++){
		if(A[i].d>p[m]) continue;
		if(A[i].a>=0){
			k[i]=m;
		}
		else{
			k[i]=lower_bound(p+1,p+m+1,A[i].d)-p;
		}
		ll tmp=A[i].v*A[i].v+2ll*A[i].a*(p[k[i]]-A[i].d);
		if(tmp>V*V){
			S.push_back(i);
		}
	}
	return (int)S.size();
}
struct U{int l,r;};
bool cmp(U a,U b){
	return a.l<b.l;
}
vector<U> arr;
int solve2(){
	int l,r;
	double v,a;
	for(auto i : S){
		v=A[i].v, a=A[i].a;
		if(A[i].a==0){
			l=lower_bound(p+1,p+m+1,A[i].d)-p, r=m;
		}
		else if(A[i].a>0){
			ll tmp=(ll)floor(1.0*(1.0*V*V-v*v)/a/2.0)+A[i].d;
			l=upper_bound(p+1,p+m+1,tmp)-p, r=m;
		}
		else if(A[i].a<0){
			ll tmp=(ll)ceil(1.0*(1.0*V*V-v*v)/a/2.0)+A[i].d;
			l=k[i], r=lower_bound(p+1,p+m+1,tmp)-p-1;
		}
		arr.push_back((U){l,r});
	}
	sort(arr.begin(),arr.end(),cmp);
	int cnt=0,t=0,lst=0;
	for(auto tmp : arr){
		l=tmp.l, r=tmp.r;
		if(l<=t && t<=r){
			lst=min(lst,r);
			continue;
		}
		else if(l<=lst){
			t=l, lst=min(lst,r);
		}
		else{
			cnt++, t=l, lst=r;
		}
	}
	return m-cnt;
}
void pre(){
	S.clear();
	arr.clear();
	return;
}
void solve(int t){
	pre();
	init();
	ans1[t]=solve1();
	ans2[t]=solve2();
	return;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t=read();
	for(int i=1;i<=t;i++){
		solve(i);
	}
	for(int i=1;i<=t;i++){
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	return 0;
}

