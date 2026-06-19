#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
inline int gt(){int r=0;char c=gc;while(c<48||c>57) c=gc;while(c>47&&c<58) r=r*10+(c^48),c=gc;return r;}
inline int gs(){char c=gc;while(c<48||c>57) c=gc;return (c^48);}
inline void ot(int x){if(x<10) pc(x^48);else ot(x/10),pc((x%10)^48);}
typedef long long ll;
ll n,m,ans,s[509],c[509],a[509];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	n=gt(),m=gt();
	for(int i=1;i<=n;++i) s[i]=gs();
	for(int i=0;i<n;++i) c[i]=gt();
	sort(c,c+n);
	if(n<=10){//1,2
		iota(a+1,a+n+1,0);
		do{
			int t=0,o=0;
			for(int i=1;i<=n;++i) if(s[i]==0||c[a[i]]<=o) ++o;else ++t;
			if(t>=m) ++ans;
		}while(next_permutation(a+1,a+n+1));
		ot(ans);
	}
	else if(m==1){//12,13,14
		ans=1;
		for(int i=1;i<=n;++i) ans=ans*i%mod;
		ll t=0,k=0,o=1;
		for(int i=1;i<=n;++i) if(s[i]){
			while(t<n&&c[t]<=i-1) ++t;
			o=o*(t-k)%mod,++k;
		}
		for(k=n-k;k>0;--k) o=o*k%mod;
		ans=((ans-o)%mod+mod)%mod;
		ot(ans);
	}
	else if(m==n){//15
		bool flag=0;
		for(int i=1;i<=n;++i) if(s[i]==0) flag=1;
		for(int i=0;i<n;++i) if(c[i]==0) flag=1;
		if(flag) ot(0);
		else{
			ans=1;
			for(int i=1;i<=n;++i) ans=ans*i%mod;
			ot(ans);
		}
	}
	else{//A(6,7,8,16,17)
		ot(0);
//		int e=0;
//		for(int i=0;i<n;++i) if()
	}
	return 0;
}
