#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
int c[510];
int ren[510];//不同耐心上线的人的数量 
int num[510];//耐心上限不同的人的可用的位置 
int dp[510][510];
int jie[510];
int ni[510];
int qpow(int a,int x){
	int shu=1,base=a;
	while(x){
		if(x&1){
			shu=(shu*base)%mod;
		}
		base=(base*base)%mod;
		x/=2;
	}
	return shu;
}
int inv(int shu){
	return qpow(shu,mod-2);
}
int C(int n,int m){
	return jie[n]*ni[m]%mod*ni[n-m]%mod;
}
int P(int n,int m){
	return jie[n]*ni[n-m]%mod;
}
signed main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	jie[0]=1;
	for(int i=1;i<=500;i++){
		jie[i]=jie[i-1]*i%mod;
	}
	ni[500]=inv(jie[500]);
	for(int i=499;i>=0;i--){
		ni[i]=(ni[i+1]*(i+1))%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ren[c[i]]++;
	}
	int now=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			now++;
		}else{
			num[cnt]=now;
			//cout<<cnt<<":"<<num[cnt]<<'\n';
			cnt++;
		}
	}
	for(int i=cnt;i<=500;i++){
		//if(i==cnt)cout<<i<<" "<<now<<'\n';
		num[i]=now;
	}
	//特殊处理耐心上限=0
	for(int i=0;i<=min(ren[0],num[0]);i++){
		dp[0][i]=C(ren[0],i)*C(num[0],i)%mod*P(i,i)%mod;
	}
	for(int i=1;i<=500;i++){
		for(int j=0;j<=500;j++){
			for(int k=0;k<=j;k++){
				if(j-k>ren[i]||num[i]<j){
					continue;
				}
				if(i==1&&j==1)cout<<i<<" "<<j<<" "<<k<<":"<<dp[i-1][k]*C(ren[i],j-k)%mod<<" "<<C(num[i]-k,j-k)%mod<<" "<<P(j-k,j-k)<<'\n'; 
				dp[i][j]=(dp[i][j]+dp[i-1][k]*C(ren[i],j-k)%mod*C(num[i]-k,j-k)%mod*P(j-k,j-k))%mod;
			}
		}
	}
	for(int i=0;i<=2;i++){
		for(int j=0;j<=3;j++){
			cout<<i<<" "<<j<<":"<<dp[i][j]<<'\n';
		}
		cout<<'\n';
	}
	int ans=0;
	for(int i=m;i<=n;i++){
		ans=(ans+dp[500][i]*P(n-i,n-i)%mod)%mod;
	}
	cout<<ans;
}
