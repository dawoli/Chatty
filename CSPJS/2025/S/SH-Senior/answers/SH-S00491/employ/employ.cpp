#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(a) {sc<<#a<<"="<<a<<"\n";}
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define qloga(a,l,r) {sc<<#a<<" : ";rep(I,l,r){sc<<a[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : ";for(auto I:a){sc<<I<<" ";}sc<<"\n";}
typedef long long ll;

const int M=998244353;
const int N=509;
int n,m;

bool s[N];
int c[N];

void solveMNE(){
	ll ans=1;	
	rep(i,1,n){
		if(!s[i])ans=0;
		if(!c[i])ans=0;
	}
	if(!ans){cout<<ans;return;}
	
	rep(i,1,n)(ans*=i)%=M;
	cout<<ans;
}

namespace BMDP{// 40MB
	const int NS=(1<<18)+100;
	ll f[19][NS],sum[NS];

	void solve(){
		f[0][0]=1;//无人放弃

		for(int S=0;S<(1<<n);S++){
			for(int i=0;i<n;i++){
				sum[S]+=(S>>i&1);
			}
		}

		for(int S=1;S<(1<<n);S++){
			for(int g=0;g<=n;g++){
				for(int i=1;i<=n;i++)if(S>>(i-1)&1){
					int T=(S^(1<<(i-1)));
					
					if(!s[sum[S]] || c[i]<=g-1){
						if(g)f[g][S]+=f[g-1][T];
					}else if(c[i]>g){
						f[g][S]+=f[g][T];
					}
					f[g][S]%=M;
				}
			}
		}
		ll ans=0;
		for(int g=0;g<=n-m;g++){
			(ans+=f[g][(1<<n)-1])%=M;
		}
		cout<<ans;
	}
}

namespace M1{
	int t[N];

	int query(int l,int r){
		if(l)return t[r]-t[l-1];
		return t[r];
	}

	void solve(){
		rep(i,1,n)t[c[i]]++;
		for(int i=1;i<=n;i++)t[i]+=t[i-1];
		
		ll sum=0;

		for(int i=1;i<=n;i++){ //面试人
			for(int j=1;j<=n;j++)if(c[i]>j-1 && s[j]){//position
				ll ans=1;
				int cnt=0;
				for(int k=1;k<j;k++){
					if(!s[k])continue;

					if(query(0,k-1)-cnt<0){ans=0;break;}
					(ans*=query(0,k-1)-cnt)%=M;
					cnt++;
				}
				for(int k=1;k<=(n-cnt-1);k++){
					(ans*=k)%=M;
				}
				(sum+=ans)%=M;
			}
		}
		cout<<sum;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>m;
	rep(i,1,n){
		char x; cin>>x;
		s[i]=(x=='1');
	}
	rep(i,1,n)cin>>c[i];


	if(n<=18){
		BMDP::solve();
		return 0;
	}
	if(m==n){
		solveMNE();
		return 0;
	}
	if(m==1){
		M1::solve();
		return 0;
	}
	cout<<0;
}
