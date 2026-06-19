#include<bits/stdc++.h>
#define N 100009
#define INF 1e18
using namespace std;
typedef long long ll;
ll n,f[N][10],g[N];
ll num[10]={6,2,5,5,4,5,6,3,7,6};
void input(){
	scanf("%lld",&n);
}
void init(){
	for(ll i=1;i<=7;i++){
		g[i]=INF;
		for(ll j=0;j<=9;j++){
			if(num[j]==i&&j!=0){
				f[i][j]=j;
				g[i]=min(g[i],j);
			}
			else f[i][j]=INF;
		}
//		printf("%lld ",i);
//		if(g[i]==INF) printf("-1\n");
//		else printf("%lld\n",g[i]);
	}
	for(ll i=8;i<=100;i++){
		g[i]=INF;
		for(ll j=0;j<=9;j++){
			f[i][j]=INF;
			if(i-num[j]<=1) continue;
			f[i][j]=g[i-num[j]]*10+j;
			g[i]=min(g[i],f[i][j]);
		}
//		printf("%lld ",i);
//		if(g[i]==INF) printf("-1\n");
//		else printf("%lld\n",g[i]);
	}
}
void solveR(){
	if(n%7==0)
		for(ll i=1;i<=n/7;i++) printf("8");
	else if(n%7==1){
		printf("10");
		for(ll i=1;i<=(n-8)/7;i++) printf("8");
	}else if(n%7==2){
		printf("1");
		for(ll i=1;i<=(n-2)/7;i++) printf("8");
	}else if(n%7==3){
		printf("200");
		for(ll i=1;i<=(n-17)/7;i++) printf("8");
	}else if(n%7==4){
		printf("20");
		for(ll i=1;i<=(n-11)/7;i++) printf("8");
	}else if(n%7==5){
		printf("2");
		for(ll i=1;i<=(n-5)/7;i++) printf("8");
	}else{
		printf("6");
		for(ll i=1;i<=(n-6)/7;i++) printf("8"); 
	}
	printf("\n");
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	init();
	ll T;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++){
		input();
		if(n==1)
			printf("-1\n");
		else if(n<=100)
			printf("%lld\n",g[n]);
		else
			solveR();
	}
	return 0;
}

