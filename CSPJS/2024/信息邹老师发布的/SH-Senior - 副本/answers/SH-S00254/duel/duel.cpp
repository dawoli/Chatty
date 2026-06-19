#include<bits/stdc++.h>
#define ar2 array<int,2>
#define ar3 array<int,3>
const int N=100005,mod=1e9+7;
int bit(int x){
	return 1ll<<x;
}
int lowbit(int x){
	return x&(-x);
}
int add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
int sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x; 
}
int mul(int x,int y){
	return 1ll*x*y%mod;
}
int powmod(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		y/=2;
		x=mul(x,x); 
	}
	return ans;
}
using namespace std;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[x]++; 
	}
	int ans=0,lst=0;
	for(int i=1;i<=N-5;i++)if(a[i]){
		int tmp=min(a[i],lst);
		lst-=tmp;
		ans+=tmp;
		lst+=a[i];
	}
	printf("%d\n",n-ans);
	return 0;
}
