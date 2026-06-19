#include<bits/stdc++.h>
using namespace std;
const int N=200009;
int T,n,a[N];
void input(){
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
bool cob[N];
int grade(){
	int blue=0,red=0,ans=0;
	for(int i=1;i<=n;i++){
		if(cob[i]){
			ans+=(a[i]==a[blue])*a[i];
			blue=i;
		}
		else{
			ans+=(a[i]==a[red])*a[i];
			red=i;
		}
	}
	return ans;
}
int bao(int i){
	if(i==n+1)
		return grade();
	cob[i]=0;
	int j=bao(i+1);
	cob[i]=1;
	return max(j,bao(i+1));
}
void solveBF(){
	cout<<bao(1)<<endl;
}
void solveDP(){
	long long dp[2009][2009]={0},ans=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=max(dp[i-1][j]+(a[i-1]==a[i])*a[i],dp[i][j]);
			dp[j][i]=max(dp[j][i-1]+(a[i-1]==a[i])*a[i],dp[j][i]);
		}
		for(int j=1;j<i;j++){
			dp[i][i-1]=max(dp[i][i-1],dp[j][i-1]+(a[j]==a[i])*a[i]);
			dp[i-1][i]=max(dp[i-1][i],dp[i-1][j]+(a[j]==a[i])*a[i]);
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,max(dp[i][n],dp[n][i]));
	cout<<ans<<endl;
}
void solve(){
	solveDP();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		input();
		if(n<=15)
			solveBF();
		else if(n<=2000)
			solveDP();
		else
			solve();
	}
	return 0;
}
