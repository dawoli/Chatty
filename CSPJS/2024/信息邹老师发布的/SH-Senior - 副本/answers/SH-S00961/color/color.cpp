#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define pc(x) putchar(x)
inline int rd(){int x=0;bool f=0;char c=gc;while(c<48||c>57) c=='-'&&(f=1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll t,n,a[200009],s[200009],f[1000009],dp[200009];
int main(){
	freopen("color.in","r",stdin),freopen("color.out","w",stdout);
	t=rd();
	while(t--){
		n=rd(),memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i) a[i]=rd(),s[i]=s[i-1]+(a[i]==a[i-1]?a[i]:0);
		for(int i=1;i<=n;++i){
			if(f[a[i]]&&f[a[i]]==i-1) dp[i]=dp[i-1]+a[i];
			else if(f[a[i]]) dp[i]=max(dp[i-1],dp[f[a[i]]+1]+(s[i-1]-s[f[a[i]]])+a[i]);
			else dp[i]=dp[i-1];
			f[a[i]]=i;
		}
		ot(dp[n]),pc('\n');
		for(int i=1;i<=n;++i) f[a[i]]=0;
	}
	return 0;
}
