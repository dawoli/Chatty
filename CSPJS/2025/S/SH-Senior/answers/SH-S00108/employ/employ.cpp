#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read(){
	TN rst=0;bool mns=0;
	char ch=getchar();
	while(ch!='-'&&!isdigit(ch))ch=getchar();
	if(ch=='-')mns=1,ch=getchar();
	while(isdigit(ch))rst=rst*10+(ch^48),ch=getchar();
	return mns?-rst:rst;
}
inline bool readb(){
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	return ch^48;
}
int TestCase=1;
inline void main_init();
inline void main_solve();
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//TestCase=read<int>();
	main_init();
	do main_solve();while(--TestCase);
}
inline void main_init(){

}
#define mod 998244353
int n,m,S[509],*s=S+5,f[505][505][505],ft[505],ans;
bool a[505];
inline void main_solve(){
	n=read<int>();
	ft[0]=1;
	for(int i=1;i<=n;++i)ft[i]=1ll*ft[i-1]*i%mod;
	m=read<int>();
	for(int i=1;i<=n;++i)a[i]=readb();
	for(int i=1;i<=n;++i)++s[read<int>()];
	for(int i=1;i<=n;++i)s[i]+=s[i-1];
	f[0][0][0]=1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){
			for(int k=1;k<=s[j];++k)f[i][j][k]=(f[i][j][k]+f[i][j][k-1])%mod;
			for(int k=0;k<=s[j];++k)
				if(a[i+1]){
					f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
					f[i+1][j][k+1]=(f[i+1][j][k+1]-f[i][j][k])%mod;
					int c=i-k,L=max(k,c-s[n]+s[j+1]),R=min(c,s[j+1]-s[j]);
					f[i+1][j+1][k+1+L]=(f[i+1][j+1][k+1+L]+1ll*f[i][j][k]*(s[j]-k))%mod;
					f[i+1][j+1][k+2+R]=(f[i+1][j+1][k+2+R]-1ll*f[i][j][k]*(s[j]-k))%mod;
				}else{
					int c=i-k,L=max(k,c-s[n]+s[j+1]),R=min(c,s[j+1]-s[j]);
					f[i+1][j+1][k+1+L]=(f[i+1][j+1][k+1+L]+1ll*f[i][j][k]*(s[j]-k))%mod;
					f[i+1][j+1][k+2+R]=(f[i+1][j+1][k+2+R]-1ll*f[i][j][k]*(s[j]-k))%mod;
					c=i-k+1,L=max(k,c-s[n]+s[j+1]),R=min(c,s[j+1]-s[j]);
					f[i+1][j+1][k+L]=(f[i+1][j+1][k+L]+f[i][j][k])%mod;
					f[i+1][j+1][k+1+R]=(f[i+1][j+1][k+1+R]-f[i][j][k])%mod;
				}
		}
	}
	for(int i=0;i<=n-m;++i){
		for(int j=1;j<=s[i];++j)f[n][i][j]=(f[n][i][j]+f[n][i][j-1])%mod;
		ans=(ans+1ll*f[n][i][s[i]]*ft[n-s[i]])%mod;
	}
	for(int i=0;i<=n;++i)ans=1ll*ans*ft[s[i]-s[i-1]]%mod;
	cout<<(ans<0?ans+mod:ans);
}

