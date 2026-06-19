#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n,a[MAXN][5],dp[MAXN][5],flag[5];
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][1]>a[j][1])
				swap(a[i][1],a[j][1]);
	for(int i=1;i<=n/2;i++){
		ans+=a[i][1];
	}
	cout<<ans<<endl;
}
int dfs(int i,int j,int f1,int f2,int f3){
	if(i==0) return 0;
	if((f1+1)<=(n/2)){
		return max(dfs(i-1,1,f1+1,f2,f3),max(dfs(i-1,2,f1+1,f2,f3),dfs(i-1,3,f1+1,f2,f3)))+a[i][1];
	}	
	if((f2+1)<=(n/2)){
		return max(dfs(i-1,1,f1,f2+1,f3),max(dfs(i-1,2,f1,f2+1,f3),dfs(i-1,3,f1,f2+1,f3)))+a[i][2];
	}
	if((f3+1)<=(n/2)){
		return max(dfs(i-1,1,f1,f2,f3+1),max(dfs(i-1,2,f1,f2,f3+1),dfs(i-1,3,f1,f2,f3+1)))+a[i][3];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				dp[i][j]=0;
				flag[j]=0;
		}	
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		bool b1=1,b2=1;
		for(int i=1;i<=n;i++)
			if(a[i][2]!=a[i][3]||a[i][3]!=0)
				b1==0;
		for(int i=1;i<=n;i++)
			if(a[i][3]!=0)
				b2==0;
		else if(b1==0) solve1();
		else if(b2==0){
			for(int i=1;i<=n;i++){
				if((flag[1]+1)<=(n/2)){
					dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][1];
				}	
				if((flag[2]+1)<=(n/2)){
					dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][2];
				}
				if((flag[3]+1)<=(n/2)){
					dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][3];
				}
			}
			cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
		}
		else cout<<max(dfs(n,1,0,0,0),max(dfs(n,2,0,0,0),dfs(n,3,0,0,0)))<<endl;	
	}
	return 0;
}
