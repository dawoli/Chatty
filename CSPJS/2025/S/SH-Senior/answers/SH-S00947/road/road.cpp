#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool v[20];
char c;
ll n,m,k,b[100010],f[100010],fa,fb,ans=1e17;
struct r{
	ll a,b,v,x;
}a[1200010];
bool cmp(r a,r b){
	return a.v<b.v;
}
ll find(ll x){
	return f[x]=(x==f[x]?x:find(f[x]));
}
void kruskal(ll x){
	ll sum=0,cnt=0;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m+k*n;i++){
		if(!v[a[i].x])continue;
		fa=find(a[i].a);
		fb=find(a[i].b);
		if(fa==fb)continue;
		f[fa]=fb;
		sum+=a[i].v;
		cnt++;
		if(cnt==n+x-1)break;
	}
	for(int i=1;i<=k;i++){
		if(v[i])sum+=b[i];
	}
	ans=min(ans,sum);
}
void dfs(ll d,ll x){
	if(d==k){
		kruskal(x);
		return;
	}
	if(b[d+1])dfs(d+1,x);
	v[d+1]=true;
	dfs(d+1,x+1);
	v[d+1]=false;
}
ll read(){
	ll ne=1,a=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')ne=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return ne*a;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		//scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].v);
		a[i].a=read();
		a[i].b=read();
		a[i].v=read();
	}
	for(int i=1;i<=k;i++){
		//scanf("%lld",&b[i]);
		b[i]=read();
		for(int j=1;j<=n;j++){
			//scanf("%lld",&a[m+(i-1)*n+j].v);
			a[m+(i-1)*n+j].v=read();
			a[m+(i-1)*n+j].a=n+i;
			a[m+(i-1)*n+j].b=j;
			a[m+(i-1)*n+j].x=i;
		}
	}
	sort(a+1,a+m+k*n+1,cmp);
	v[0]=true;
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
