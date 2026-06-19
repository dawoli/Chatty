#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=509,MOD=998244353;
int n,a[5005],s[5005],ans;
int f[N][50005]={1};//前i项总长至少为j时有多少种方案 
int c[5005][5005];
void solve_sp(){
	long long res=0;
	for(int i=0;i<=n;i++) c[i][0]=c[i][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=MOD;
		}
	}
	for(int i=3;i<=n;i++){
		res+=c[n][i];
		res%=MOD;
	}
	cout<<res<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=0;i<N;i++) f[i][0]=1;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	if(s[n]==n) solve_sp();
	else{
		
	for(int i=1;i<=n;i++){
		for(int j=s[i];j>=1;j--){
			f[i][j]=f[i-1][j];
			if(j>=a[i]) f[i][j]+=f[i-1][j-a[i]];
			f[i][j]%=MOD;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=s[i];j>=0;j--){
			f[i][j]+=f[i][j+1];
			f[i][j]%=MOD;
		}
	for(int i=3;i<=n;i++){
		ans+=f[i-1][a[i]+1];
		ans%=MOD;
	}
	cout<<ans<<endl;

	}
	return 0;
}
