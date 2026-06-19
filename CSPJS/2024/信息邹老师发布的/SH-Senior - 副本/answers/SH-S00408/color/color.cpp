#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD=998244353;
const ll MN=200005;
const ll INF=0x3f3f3f3f;


ll Read() {
	ll t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') {
		t=t*10+c-'0';
		c=getchar();
	}
	return t*f;
}
void Prll(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	} 
	if(x<10) {
		putchar((char)(x%10+'0')); 
	    return;
	}
	Prll(x/10);
	putchar((char)(x%10+'0')); 
	return;
}

ll t,n,a[MN],c[MN],ans; 
ll gain() {
	ll aa0=-1,aa1=-1,cnt=0; //目前最右边一个0，最右边一个1 
	for(ll i=1;i<=n;++i) {
		if(c[i]==0) {
			if(aa0!=-1) {
				if(a[i]==aa0) cnt+=a[i];
			} 
			aa0=a[i];
		}
		if(c[i]==1) {
			if(aa1!=-1) {
				if(a[i]==aa1) cnt+=a[i];
			} 
			aa1=a[i];
		}
	}
	return cnt;
}
void dfs(ll now) {
	if(now==(n+1)) {
        ll aaa=gain();
        ans=max(ans,aaa);
	} else {
		c[now]=0;
		dfs(now+1);
		c[now]=1;
		dfs(now+1);
	}
	return;
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
//    scanf("%lld",&t);
    t=Read();
    while(t--) {
    	ans=0;
    	n=Read();
//    	scanf("%lld",&n);
    	for(ll i=1;i<=n;++i) {
//    		scanf("%lld",&a[i]);
    		a[i]=Read();
		}
		dfs(1);
		Prll(ans);
		putchar('\n');
//		printf("%lld\n",ans);
	}

	return 0; 
} 

