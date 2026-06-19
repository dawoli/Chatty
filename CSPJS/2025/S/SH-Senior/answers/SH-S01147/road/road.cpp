#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,a[20][10010],c[20],ff,o,f[10020],d[10020],s,m2=0;
bool vs[20];
struct p{
	long long u,v,w;
}e[1000010],b[1000010];
bool cmp1(p x,p y){
	return x.w<y.w;
}
long long fd(long long x){
	while(f[f[x]]!=f[x])
		f[x]=f[f[x]];
	return f[x];
}
long long cn(long long x,long long y){
	x=fd(x),y=fd(y);
	f[y]=x;
	d[x]+=d[y];
	return d[x];
}
long long q(long long y){
	long long s=0,j=1;
	sort(b+1,b+m2+1,cmp1);
	for(int i=1;i<=n+k;++i){
		f[i]=i;
		if(i<=n)
			d[i]=1;
		else
			d[i]=0;
	}
	for(int i=1;i<=m;++i){
		while(j<=m2&&b[j].w<=e[i].w){
			if(fd(b[j].u)!=fd(b[j].v)){
				s+=b[j].w;
				if(cn(b[j].u,b[j].v)==n)
					return s;
			}
			j++;
		}
		if(fd(e[i].u)!=fd(e[i].v)){
			s+=e[i].w;
			if(cn(e[i].u,e[i].v)==n)
				return s;
		}
	}
	while(j<=m2){
		if(fd(b[j].u)!=fd(b[j].v)){
			s+=b[j].w;
			if(cn(b[j].u,b[j].v)==n)
				return s;
		}
		j++;
	}
	return s;
}
void dfs(long long cst,long long x,long long y){
	if(x==k+1){
		s=min(s,q(y)+cst);
		return;
	}
	if(!vs[x]){
		dfs(cst,x+1,y);
		while(e[m2].w==1e18)
			m2--;
		for(int i=1;i<=n;++i)
			b[++m2]={i,n+x,a[x][i]};
		dfs(cst+c[x],x+1,y+1);
		for(int i=1;i<=m2;++i)
			if(b[i].v==n+x)
				b[i].w=1e18;
	}
	else
		dfs(cst,x+1,y+1);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
		e[i].u=x;
		e[i].v=y;
		e[i].w=z;
	}
	o=0;
	for(int j=1;j<=k;++j){
		ff=1;
		scanf("%lld",&c[j]);
		if(c[j]!=0)
			ff=0;
		else
			vs[j]=1;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[j][i]);
			if(ff){
				b[++m2]={i,n+j,a[j][i]};
			}
		}
	}
	sort(e+1,e+m+1,cmp1);
	s=1e18;
	dfs(0,1,0);
	printf("%lld",s);
	return 0;
}
