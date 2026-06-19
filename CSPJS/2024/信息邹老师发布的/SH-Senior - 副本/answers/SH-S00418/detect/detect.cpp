#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,l,V,p[100100];
struct car{
	ll d,v,a;
}c[100100];
bool cmp(car x,car y){
	return x.a<y.a;
}
void Main(){
	scanf("%lld%lld%lld%lld",&n,&m,&l,&V);
	bool flag1=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
		if(c[i].a!=0)flag1=0;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&p[i]);
	}
	if(flag1){
		ll ma=0,ans=0;
		for(ll i=1;i<=m;i++){
			ma=max(ma,p[i]);
		}
		for(ll i=1;i<=n;i++){
			if(c[i].d<=ma && c[i].v>V)ans++;
		}
		printf("%lld %lld\n",ans,m-((ans==0)?0:1));
		return ;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		Main();
	}
	return 0;
}