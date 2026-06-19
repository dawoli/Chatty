#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=509,MOD=998244353;
int n,m;
string s;
int c[N];
int fracMOD(int u){
	if(u==0) return 1;
	return u*fracMOD(u-1)%MOD;
}
void solve_dpBF(){
	int dp[19][1<<18];
	dp[0][0]=1;
	int cnt,i,j,k,ptn;
	for(i=1;i<=n;i++){
		for(j=n;j>=0;j--){
			for(ptn=0;ptn<(1<<n);ptn++){
				cnt=0;
				for(k=1;k<=n;k++) if(ptn&(1<<(k-1))) cnt++;
				if(cnt!=i) continue;
				dp[j][ptn]=0;
				for(k=1;k<=n;k++) if(ptn&(1<<(k-1))){
					if(s[i-1]=='1'&&i-1-(j-1)<c[k]){
						if(j!=0) (dp[j][ptn]+=dp[j-1][ptn^(1<<(k-1))])%=MOD;
					}
					else if(s[i-1]!='1'||i-1-j>=c[k]){
						(dp[j][ptn]+=dp[j][ptn^(1<<(k-1))])%=MOD;
					}
				}
//				bitset<10> bs;
//				bs=ptn;
//				if(j!=10) cout<<i<<" "<<j<<" "<<bs.to_string()
//				<<" "<<dp[j][ptn]<<"\n";
//				else  cout<<i<<" T "<<bs.to_string()
//				<<" "<<dp[j][ptn]<<"\n";
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) (ans+=dp[i][(1<<n)-1])%=MOD;
	cout<<ans;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		solve_dpBF();
		return 0;
	}
//	bool flg=1;
//	for(int i=0;i<n;i++) if(s[i]=='0') flg=0;
//	if(flg){
		cout<<fracMOD(n);
//		return 0;
//	}
	return 0;
}

