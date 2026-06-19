#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=507,MOD=998244353;
ll n,m,ans,a[N],c[N],s[N],f[2][N][N],C[N][N],fac[N];
char S[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	for (int i=0;i<N;++i) for (int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	for (int i=fac[0]=1;i<N;++i){
		fac[i]=fac[i-1]*i%MOD;
	}
	cin>>n>>m>>(S+1);
	for (int x,i=1;i<=n;++i){
		a[i]=S[i]&1;
		cin>>x;++c[x];
	}
	s[0]=c[0];
	for (int i=1;i<=n;++i){
		s[i]=s[i-1]+c[i];
	}
	f[0][0][0]=1;
	int now=1,pre=0;
	for (int i=1;i<=n;++i){
		for (int j=0;j<i;++j) for (int k=0;k<=s[j];++k) if (f[pre][j][k]){
//			cout<<i-1<<' '<<j<<' '<<k<<' '<<f[pre][j][k]<<endl;
			ll tmp=f[pre][j][k];f[pre][j][k]=0;
			if (k<s[j]){
				ll o=tmp*(s[j]-k)%MOD;
				int lim=min(c[j+1],i-1ll-k);
				for (int l=0;l<=lim;++l){
					(f[now][j+1][k+1+l]+=o*C[i-1-k][l]%MOD*C[c[j+1]][l]%MOD*fac[l])%=MOD;
				}
			}
			if (a[i]){
				(f[now][j][k]+=tmp)%=MOD;
			}
			else{
				int lim=min(c[j+1]-1,i-1ll-k);
				for (int l=0;l<=lim;++l){
					(f[now][j+1][k+1+l]+=tmp*C[i-1-k][l]%MOD*C[c[j+1]][l+1]%MOD*fac[l+1])%=MOD;
				}
				lim=min(c[j+1],i-1ll-k);
				for (int l=0;l<=lim;++l){
					(f[now][j+1][k+l]+=tmp*C[i-1-k][l]%MOD*C[c[j+1]][l]%MOD*fac[l])%=MOD;
				}
			}
		}
		swap(now,pre);
	}
	for (int i=0;i<=n-m;++i){
		ll k=n-s[i],tmp=f[pre][i][s[i]];
//		cout<<n<<' '<<i<<" "<<s[i]<<' '<<tmp<<endl;
		for (int j=i+1;j<=n;++j){
			(tmp*=C[k][c[j]]*fac[c[j]]%MOD)%=MOD;
			k-=c[j];
		}
		(ans+=tmp)%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
