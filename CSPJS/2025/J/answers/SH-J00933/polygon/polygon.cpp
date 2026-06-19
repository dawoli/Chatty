#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define el <<"\n"
#define log(x) cout<<#x<<": "<<x el
#define logArr(A,l,r) cout<<#A<<"["<<l<<"..."<<r<<"] = ";rep(i,l,r)cout<<A[i]<<" ";cout el
#define fi first
#define sc second
using namespace std;
typedef long long ll;const ll mod=998244353;
ll f[20005],g[20005];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	map<ll,ll>M;
	cin>>n;
	rep(i,1,n){
		int x;
		cin>>x;
		M[x]++;
	}
	f[0]=1;
	ll ans=0,s=1,l=0;
	for(auto i:M){
		rep(j,1,i.sc){
			s*=2;
			s%=mod;
			for(int k=11000;k>=i.fi;k--){
				f[k]+=f[k-i.fi];
				f[k]%=mod;
			}
		}
		ans+=s-l;
		ans%=mod;
		rep(j,0,2*i.fi){
			ans-=f[j]-g[j];
			ans%=mod;
		}
		rep(j,0,11000){
			g[j]=f[j];
		}
//		cout<<ans el;
//		logArr(f,0,20);
//		cout el;
		l=s;
	}
//	cout<<ans;
	cout<<(ans+mod)%mod;
	return 0;
}
// 10:16 AK
