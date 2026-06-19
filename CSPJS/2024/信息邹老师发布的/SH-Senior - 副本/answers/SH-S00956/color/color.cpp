#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=1e6+5;
int n,a[MAXN];
long long dp[MAXN][MAXN];
long long ans;
void solve(){
	memset(dp,0,sizeof(dp));
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long temp;
	for(int i=1;i<=n;i++){
		temp=0;
		for(int j=i-1;j>=0;j--){
			if(j!=i-1&&a[j+1]==a[j+2]){
				temp+=a[j+1];
			}
			for(int k=0;k<j;k++){
//				printf("###%d %d %d %lld %lld\n",i,j,k,dp[j][k],temp+(a[k]==a[j+1])*a[k]);
				dp[i][j]=max(dp[i][j],dp[j][k]+temp+(a[k]==a[j+1])*a[k]);
			}
//			if(j==0){
//				printf("%d %d %lld\n",i,j,temp);
//			}else{ 
//				printf("%d %d %lld\n",i,j,dp[i][j]);
//			}
		}
		dp[i][0]=temp;
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,dp[n][i]);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2e4+5;
const int MAXM=1e6+5;
int n,a[MAXN],lst[MAXN],g[MAXN];
long long dp[MAXN][MAXN],f[MAXN];
vector<int> vc[MAXM];
void solve(){
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=0;i<MAXM;i++){
		vc[i].clear();
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(vc[a[i]].size()!=0){
			lst[i]=vc[a[i]].back();
		}else{
			lst[i]=0;
		}
		vc[a[i]].push_back(i);
	}
	long long temp;
	for(int i=1;i<=n;i++){
		temp=0;
		for(int j=i-1;j>=0;j--){
			if(j!=i-1&&a[j+1]==a[j+2]){
				temp+=a[j+1];
			}
//			for(int k=0;k<j;k++){
////				printf("###%d %d %d %lld %lld\n",i,j,k,dp[j][k],temp+(a[k]==a[j+1])*a[k]);
//				dp[i][j]=max(dp[i][j],dp[j][k]+temp+(a[k]==a[j+1])*a[k]);
//			}
			dp[i][j]=f[j]+temp;
			auto it=upper_bound(vc[a[j+1]].begin(),vc[a[j+1]].end(),j-1);
			if(it!=vc[a[j+1]].begin()){
				if((*prev(j))==g[i]){
					dp[i][j]=max(dp[i][j],dp[j][*prev(it)]+temp+a[j+1]);
				}else{
					dp[i][j]=max(dp[i][j],dp[j][*prev(it)]+temp+a[j+1]);
				}
			}
		}
		for(int j=0;j<=i;j++){
			if(lst[j]!=0){
				dp[i][j]=max(dp[i][j],dp[i][lst[j]]);
			}
			if(dp[i][j]>f[i]){
				g[i]=j;
				f[i]=dp[i][j];
			}
//			printf("%d %d %lld\n",i,j,dp[i][j]);
		}
	}
	printf("%lld\n",f[n]);
}
int main(){
	freopen("color2.in","r",stdin);
	freopen("color2.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
*/
