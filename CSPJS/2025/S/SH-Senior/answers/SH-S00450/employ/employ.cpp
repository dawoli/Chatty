#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
int n,m,c[505],ans,dp[505][505];//前i天有j个人未录用时的方案数 
string s;
bool vis[505];
void dfs(int step,int acc){//acc是之前通过的人数 
	if(acc+n-step<m-1)return;
	if(step>n){
		if(acc>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[step]=='0'||step-acc-1>=c[i])dfs(step+1,acc);//未通过的 
			else dfs(step+1,acc+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=10)dfs(1,0);
	else{
//		for(int i=1;i<=n;i++){//枚举天数 
//			for(int j=1;j<=n;j++){//第i天第j个人来面试 
//				for(int k=0;k<c[j]&&k<=i;k++){//未录用的人数为k 
//					dp[i][k]=
//					if(s[i]=='1'){//如果可通过 
//						dp[i][k]=max(dp[i][k],dp[i][k]+dp[i-1][k]+1);
//					}
//					else{//如果不能通过 
//						dp[i][k+1]=max(dp[i][k+1],dp[i][k+1]+dp[i-1][k]);
//					}
//				}
//			}
//		}
		ans=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
