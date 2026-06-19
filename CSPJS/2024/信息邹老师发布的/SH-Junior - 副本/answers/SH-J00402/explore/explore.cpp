#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,k,x,y,d;
ll v[1010][1010];
char s[1010][1010];
void Main(){
	scanf("\n%lld %lld %lld %lld %lld %lld",&n,&m,&k,&x,&y,&d);
	for(ll i=1;i<=n;i++){
		scanf("\n");
		for(ll j=1;j<=m;j++){
			scanf("%c",&s[i][j]);
		}
	}
	memset(v,0,sizeof(v));
	v[x][y]=1;
	for(ll i=1;i<=k;i++){
		ll nx=x,ny=y;
		if(d==0)ny++;
		else if(d==1)nx++;
		else if(d==2)ny--;
		else nx--;
		if(nx<1 || nx>n || ny<1 || ny>m || s[nx][ny]=='x'){
			d=(d+1)%4;
			continue;
		}
		x=nx;
		y=ny;
		v[x][y]=1;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(v[i][j])ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		Main();
	}
	return 0;
}