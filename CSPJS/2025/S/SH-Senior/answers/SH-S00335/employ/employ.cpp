#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 510 
int n,m,c[N],dp[(1LL<<18)][20],ans,l[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		int flag=1;
		for(auto x:s){
			flag&=(x!='0');
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				flag=0;
			}
			flag*=i;
			flag%=mod;
		}
		cout<<flag<<'\n';
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		for(int i=1;i<=n;i++){
			l[i]=i-1;
			if(s[i-1]=='0'){
				l[i]=n;
			}
		}
		sort(l+1,l+n+1);
		sort(c+1,c+n+1); 
		int now=1,ex=1;
		for(int i=1;i<=n;i++){
			while(now<=n&&c[now]<=l[i]){
				now++;
			}
			ex*=max(now-i,0LL);
			ex%=mod;
		}
		cout<<(ans+mod-ex)%mod<<'\n';
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<=(1LL<<n)-1;i++){
		for(int j=1;j<=n;j++){
			if(!(i&(1LL<<j-1))){
				for(int k=0;k<=n;k++){
					int flag=((__builtin_popcount(i)-k<=c[j]-1)&&(s[__builtin_popcount(i)]=='1'));
					dp[i+(1LL<<j-1)][k+flag]+=dp[i][k];
					dp[i+(1LL<<j-1)][k+flag]%=mod;
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		if(i>=m){
			ans+=dp[(1LL<<n)-1][i];
			ans-=(ans>=mod)*mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
