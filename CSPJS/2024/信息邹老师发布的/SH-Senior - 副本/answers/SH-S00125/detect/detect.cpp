#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+5;
ll T,p[maxn],d[maxn],v[maxn],a[maxn];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
struct fraction{
	ll a,b;
	fraction operator*(const fraction &x)const{
		fraction ret;
		ret.a=a*x.a;
		ret.b=b*x.b;
		ll g=gcd(ret.a,ret.b);
		ret.a/=g;ret.b/=g;
		return ret;
	}
	fraction operator+(const fraction &x)const{
		fraction ret;
		ret.b=b*x.b;
		ret.a=a*x.b+b*x.a;
		ll g=gcd(ret.a,ret.b);
		ret.a/=g;ret.b/=g;
		return ret;
	}
};
struct node{
	ll s,e;
}car[maxn];
ll read(){
	ll ret=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=(ret<<1)+(ret<<3)+(c-'0');
		c=getchar();
	}
	return x*ret;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
//	scanf("%lld",&T);
	T=read();
	while(T--){
		ll n,m,L,V,ans=0;
		n=read();m=read();L=read();V=read();
//		scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
		for(ll i=1;i<=n;i++){
//			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			d[i]=read();v[i]=read();a[i]=read();
		}
		for(ll i=1;i<=m;i++) p[i]=read(); //scanf("%lld",&p[i]);
		for(ll i=1;i<=n;i++){
			if(a[i]==0&&v[i]>V&&d[i]<=p[m]){
				ans++;
				car[ans].s=d[i];car[ans].e=L;
			}
			if(a[i]>0){
				ll ss;
				if(v[i]<=V){
					fraction S={d[i],1},vv={v[i],1},aa={a[i],1};
					ll g=gcd(V-v[i],a[i]);
					fraction devid={1,2},t={(V-v[i])/g,a[i]/g};
					S=S+t*vv+t*t*devid*aa;
					ss=S.a/S.b+1;
				}
				else ss=d[i];
				if(ss<=p[m]){
					ans++;
					car[ans].s=ss;car[ans].e=L;
				}
			}
			if(a[i]<0&&v[i]>V){
				ll ee;
				fraction S={d[i],1},vv={v[i],1},aa={a[i],1};
				ll g=gcd(V-v[i],a[i]);
				fraction devid={1,2},t={(V-v[i])/g,a[i]/g};
				S=S+t*vv+t*t*devid*aa;
				if(S.b==1) ee=S.a-1;
				else ee=S.a/S.b;
				ll fir=lower_bound(p+1,p+m+1,d[i])-p,la=upper_bound(p+1,p+m+1,ee)-p-1;
				if(fir<=m&&fir<=la){
					ans++;
					car[ans].s=d[i];car[ans].e=ee;
				}
			}
		}
		printf("%lld ",ans);
//		for(ll i=1;i<=ans;i++)
//			printf("%lld %lld\n",car[i].s,car[i].e);
		sort(car+1,car+ans+1,[](node x,node y){return x.e<y.e;});
		deque<pair<ll,ll> > Q;//first：最后一个测速器，second：测速器数量
		Q.push_back(make_pair(0,0));
		p[0]=-1;
		for(ll i=1,j=1;i<=ans;i++){    //i是车的编号，j是测速器的编号
			while(j<m&&p[j+1]<=car[i].e) j++;
			while(!Q.empty()&&p[Q.front().first]<car[i].s){
				pair<ll,ll> cur=make_pair(j,Q.front().second+1);
				Q.pop_front();
				while(!Q.empty()&&cur.second<=Q.back().second) Q.pop_back();
				Q.push_back(cur);
			}
		}
		printf("%lld\n",m-Q.front().second);
	}
	return 0;
}
