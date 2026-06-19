#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n,m,L,V,p[N],s[N],tot;
struct Restriction{ll x,y;} r[N];
struct Car{
	ll d,v,a;
} c[N];
bool cmp(const Restriction&a,const Restriction&b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
void read(ll &x){
	char c=getchar();
	while(!(c=='-'||c>='0'&&c<='9'))
	    c=getchar();
	bool t=0;
	if(c=='-')
	    t=1,c=getchar();
	x=0;
	while(c>='0'&&c<='9')
	    x=x*10+c-'0',c=getchar();
	if(t)x=-x;
}
void solve(){
	read(n);read(m);read(L);read(V);
	for(ll i=1;i<=n;i++)
	    read(c[i].d),read(c[i].v),read(c[i].a);
	for(ll i=1;i<=m;i++)
	    read(p[i]);
	for(ll i=0;i<=m;i++)
	    s[i]=0;
	tot=0;
	ll mn,mx,fnd,tmp1,tmp2;
	for(ll i=1;i<=n;i++){
		if(c[i].a==0){
			if(c[i].v<=V)continue;
			mn=lower_bound(p+1,p+m+1,c[i].d)-p;
			if(mn<=m)
			    r[++tot]=(Restriction){mn-1,m};
		}else if(c[i].a>0){
			if(c[i].v>V)
			    fnd=c[i].d;
			else
				fnd=(V*V-c[i].v*c[i].v)/(2*c[i].a)+1+c[i].d;
			mn=lower_bound(p+1,p+m+1,fnd)-p;
			if(mn<=m)
			    r[++tot]=(Restriction){mn-1,m};
		}else{
			if(c[i].v<=V)continue;
			mn=lower_bound(p+1,p+m+1,c[i].d)-p;
			tmp1=c[i].v*c[i].v-V*V;
			tmp2=-2*c[i].a;
			if(tmp1%tmp2==0)
			    fnd=tmp1/tmp2-1+c[i].d;
			else fnd=tmp1/tmp2+c[i].d;
			mx=upper_bound(p+1,p+m+1,fnd)-p-1;
			if(mn<=mx)
			    r[++tot]=(Restriction){mn-1,mx};
		}
	}
	sort(r+1,r+tot+1,cmp);
	ll cur=1;
	for(ll i=0;i<=m-1;i++){
		s[i+1]=max(s[i+1],s[i]);
		while(cur<=tot&&r[cur].x==i){
			s[r[cur].y]=max(s[r[cur].y],s[i]+1);
			cur++;
		}
	}
	printf("%lld %lld\n",tot,m-s[m]);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	read(T);
	while(T--)solve();
	return 0;
}
