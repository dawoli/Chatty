#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009][19];
int ans=-1;
int nums[100009];
void check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=a[i][nums[i]];
	}
	ans=max(ans,tmp);
	//cout<<tmp<<endl;
}
void dfs(int x,int yn,int en,int sn){
	if(x>n){
		check();
		return ;
	}
	if(yn<n/2){
		nums[x]=1;
		dfs(x+1,yn+1,en,sn);
	}
	if(en<n/2){
		nums[x]=2;
		dfs(x+1,yn,en+1,sn);
	}
	if(sn<n/2){
		nums[x]=3;
		dfs(x+1,yn,en,sn+1);
	}
}
int tp[200009];
int dp[200009][2];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n<=30){
			ans=-1;
			dfs(1,0,0,0);
			cout<<ans<<endl;
		}
		else{
			bool ok1=1,ok2=1;
			for(int i=1;i<=n;i++){
				if(a[i][2]!=0 or a[i][3]!=0) ok1=0;
				if(a[i][3]!=0) ok2=0;
			}
			if(ok1){
				for(int i=1;i<=n;i++){
					tp[i]=a[i][1];
				}
				sort(tp+1,tp+n+1);
				long long ans=0;
				for(int i=n;i>n/2;i--){
					ans+=tp[i];
				}
				cout<<ans<<endl;
			}
			else if(ok2){
				int nu=0;
				for(int i=1;i<=n;i++){
					nu++;
					tp[nu]=a[i][1];
					nu++;
					tp[nu]=a[i][2];
				}
				dp[1][0]=0;
				dp[1][1]=tp[1];
				for(int i=2;i<=nu;i++){
					dp[i][1]=dp[i-1][0]+tp[i];
					dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				}
				cout<<max(dp[nu][0],dp[nu][1])<<endl;
			}
		}
	}
	return 0;
} 
