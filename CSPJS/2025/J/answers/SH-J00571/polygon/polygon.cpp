#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5001;
const ll mod=998244353;
int n;
ll a[maxn];
ll dfs(int pos,ll mx,ll sum){
	if(pos==n+1){
		if(sum>mx*2){
			return 1;
		}else{
			return 0;
		}
	}
	ll ret=dfs(pos+1,max(mx,a[pos]),sum+a[pos]);
	ret+=dfs(pos+1,mx,sum);
	return ret%mod;
}
ll ksm(int bx,ll b){
	if(bx==1) return 1;
	if(b==0) return 1;
	bx%=mod;
	if(b%2==1){
		ll ret=ksm(bx*bx,b/2)%mod*bx%mod;
		return ret;
	}else{
		ll ret=ksm(bx*bx,b/2)%mod;
		return ret;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) A=0;
	}
	if(A){
		ll r1=ksm(2,n)%mod;
		r1=(r1-1-n+mod)%mod;
		r1=r1-(n-1)*n/2;
		r1=(r1+mod)%mod;
		cout<<r1;
	}else{
		sort(a+1,a+n+1);
		cout<<dfs(1,0,0)%mod;
	}
	fclose(stdin);
	fclose(stdout);
}
