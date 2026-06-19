// #Shang4Shan3Ruo6Shui4

// enum $n$ sticks
// n \le 5000
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5000+5;
const ll M=998244353;
ll n;
ll a[N],s[N];
ll find(ll l,ll r,ll k){ // how many choices, their sum > k
	// > !
	// l.choose or not_choose
	ll res;
	if(l>r) res=(0>k);
	else if(s[r]-s[l-1]<=k) res=0;
	else if(k<0) res=(1<<(r-l+1)); // any choice make sum>k
	else{
		ll c=find(l+1,r,k-a[l]);
		ll nc=find(l+1,r,k);
		res=(c+nc)%M;
	}
//for(ll i=1;i<l;i++)printf(" ");printf("find(%3lld, %3lld, %3lld)  =  %5lld\n",l,r,k,res);
	return res;
}

void solvea1(){
	ll res=1;
	for(ll i=1;i<=n;i++) // get 2^n
		res=(res<<1)%M;
	res-=n*(n-1)/2; // 2
	res-=n; // 1
	res-=1; // 0
	printf("%lld\n",(res%M+M)%M);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]==a[1]){ solvea1(); return 0; }
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//for(int i=1;i<=n;i++) printf("%2d: %3d\n",i,a[i]);
	ll cnt=0;
	for(ll li=3;li<=n;li++){ // longest 's index
//printf("li = %3lld\n",li);
		cnt=(cnt
			 + find(1,li-1,a[li])
			) % M;
//printf("add: %3lld\n",find(1,li-1,a[li]));
	}
	printf("%lld\n",(cnt+M)%M);
	return 0;
}

