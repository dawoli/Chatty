#include<bits/stdc++.h>
#define int long long
#define ar2 array<int,2>
#define ar3 array<int,3>
const int N=1000005,mod=1e9+7;
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
int n,a[N],f[N],lst[N],pre[N];
void solve(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+(a[i]==a[i-1]?a[i]:0);
	}
//	if(n!=100)return ;
	for(int i=1;i<=N-5;i++){
		lst[i]=0;
	}
	for(int i=1;i<=n;i++){
		f[i]=0;
		if(lst[a[i]]==0){
			lst[a[i]]=i;
			f[i]=f[i-1];
			continue;
		}
		int x=lst[a[i]];
		lst[a[i]]=i;
//		if(i==n)printf("kkk %d\n",a[i]+pre[i-1]-pre[x]);
		f[i]=max(f[i-1],a[i]+pre[i-1]-pre[x]+f[min(x+1,i-1)]);
		
	}
	printf("%lld\n",f[n]);
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--)solve(); 
	return 0;
}
