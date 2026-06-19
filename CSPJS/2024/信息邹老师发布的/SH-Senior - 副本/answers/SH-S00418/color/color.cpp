#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,a[100100],ans,c[100100],b[100100];
void dfs(ll i){
	if(i==n+1){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			ll num=-1;
			for(ll k=j-1;k>=1;k--){
				if(c[k]==c[j]){
					num=k;
					break;
				}
			}
			if(num==-1 || a[j]!=a[num])continue;
			else cnt+=a[j];
		}
		ans=max(ans,cnt);
		return;
	}
	dfs(i+1);
	c[i]=1;
	dfs(i+1);
	c[i]=0;
}
void Main(){
	scanf("%lld",&n);
	ans=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=15){
		dfs(1);
	}
	else{
		for(ll i=1;i<=n;i++){
			for(ll j=i-1;j>=1;j--){
				if(a[i]==a[j]){
					for(ll k=j;k<=i;k++){
						b[k]++;
						c[k]+=a[i];
					}
					break;
				}
			}
		}
		for(ll i=1;i<=n;i++){
			if(b[i]<=2)ans=max(ans,c[i]);
		}
		memset(c,0,sizeof(c));
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		Main();
	}
	return 0;
}