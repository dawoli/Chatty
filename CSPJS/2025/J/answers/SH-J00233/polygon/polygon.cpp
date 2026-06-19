#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010];
int dp[5010][5010];
int n;
int cnt=0;
void solve1(int pos,int len,int goal,int sum,int maxval){
	if(len==goal){
		if(sum>2*maxval){
			cnt++;
			cnt%=mod;
		}
		return ;
	}
	for(int i=pos+1;i<=n;i++){
		solve1(i,len+1,goal,sum+a[i],max(a[i],maxval));
	}
}
void solve2(){
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=i;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=3;i<=n;i++){
//		cout<<"C("<<i<<","<<n<<")="<<dp[n][i]<<endl;
		cnt+=dp[n][i];
		cnt%=mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	if(flag){
		solve2();
		cout<<cnt<<endl;
	}
	else{
		for(int i=3;i<=n;i++){
			solve1(0,0,i,0,0);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
