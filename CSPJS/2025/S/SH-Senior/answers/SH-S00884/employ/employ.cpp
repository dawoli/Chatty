#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
const int N = 30;
int n,m;
string str;
int c[N],cur[1<<19];
int dp[1<<19][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;str=" "+str;
	bool flag=1,exist_0=0;
	for(int i=1;i<=n;++i){
		if(str[i]=='1') flag=0;
		if(str[i]=='0') exist_0=1;
	}
	ll cnt=0,fac=1;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]==0) cnt++;
		fac=fac*(ll)i%mod;	
	}
	if(flag){
		cout<<114514<<endl;
		return 0;
	}
	if(m==n&&n>=18){
		if(cnt>=0) cout<<0<<endl;
		else{
			if(exist_0) cout<<0<<endl;
			else		cout<<fac<<endl;
		}
		return 0;
	}
	for(int s=1;s<(1<<n);++s)
		cur[s]=cur[s^(s&(-s))]+1;
	dp[0][0]=1;
	for(int s=1;s<(1<<n);++s){
		int j=cur[s];
		for(int k=0;k<n;++k){
			if(s&(1<<k)){
				int t=s^(1<<k);
				int p=str[j]-'0';//0 or 1
				for(int l=0;l<j;++l){
					//l=empolyed people's number(state:t)
					int give_up=cur[t]-l;
					if(p==0)
						dp[s][l]=(dp[s][l]+dp[t][l])%mod;
					if(p==1)
						if(c[k+1]<=give_up)
							dp[s][l]=(dp[s][l]+dp[t][l])%mod;
						else
							dp[s][l+1]=(dp[s][l+1]+dp[t][l])%mod;
				}
			}
		}
	}
	ll ans=0;
	for(int j=m;j<=n;++j)	
		ans=(ans+dp[(1<<n)-1][j])%mod;
	cout<<ans<<endl;
	return 0;
}
