#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=509,mod=998244353;
int n,m,c[N],f[(1<<18)+9][N],a[N],b[N],h;
string s;
void sol1(){
	for(int i=1;i<=n;i++) a[c[i]]++;
	for(int i=0;i<n;i++)if(s[i]=='1') b[++h]=i;
	if(!h){
		puts("0");
		return;
	}
	b[0]=-1;
	int ans=1,tot=0;
	for(int i=1;i<=h;i++){
		for(int j=b[i-1]+1;j<=b[i];j++) tot+=a[j];
		ans=ans*tot%mod;
		tot--;
	}
	for(int i=1;i<=n-h;i++) ans=ans*i%mod;
	int jc=1;
	for(int i=2;i<=n;i++) jc=jc*i%mod;
	cout<<(jc-ans+mod)%mod<<endl;
}
void sol2(){
	m=n-m;
	f[0][0]=1;
	for(int p=0;p<(1<<n)-1;p++){
		int t=__builtin_popcount(p);
		for(int j=0;j<=min(t,m);j++){
			for(int i=0;i<n;i++)if(!(p&(1<<i))){
				if(j<c[i+1]&&s[t]=='1') f[p+(1<<i)][j]=(f[p+(1<<i)][j]+f[p][j])%mod;
				else f[p+(1<<i)][j+1]=(f[p+(1<<i)][j+1]+f[p][j])%mod;
			}
		}
	}
	int ans=0;
	for(int j=0;j<=m;j++) ans=(ans+f[(1<<n)-1][j])%mod;
	cout<<ans<<endl;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==1) sol1();
	else sol2();
	return 0;
}
