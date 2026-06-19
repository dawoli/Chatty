#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int N2=210;
int T;
int n, lim;
int a[N][4], b[N];
ll dp[N2][N2][N2], ans;
//dp[j][k][l] = 有 j 个人分到1组 , k 个人分到 2 组 , l个人分到3组 的最大满意度 
bool special_a=true;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>T;
	while(T--){
		cin>>n;
		lim = n/2;
		special_a=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i] = a[i][1];
			if(a[i][2]!=0 || a[i][3]!=0) special_a=false;
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0][0]=0;
		ans=-1;
		
		if(special_a){
			ans=0;
			sort(b+1, b+n+1);
			for(int i=lim+1;i<=n;i++) ans+=b[i];
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=lim;j>=0;j--){
					for(int k=lim;k>=0;k--){
						for(int l=lim;l>=0;l--){
							if(dp[j][k][l]!=-1){
								dp[j+1][k][l] = max(dp[j+1][k][l], dp[j][k][l] + a[i][1]);
								dp[j][k+1][l] = max(dp[j][k+1][l], dp[j][k][l] + a[i][2]);
								dp[j][k][l+1] = max(dp[j][k][l+1], dp[j][k][l] + a[i][3]);
							}
						} 
						//cout<<j<<" "<<k<<" "<<dp[j][k]<<'\n';
					}
				}
			}
			
			for(int j=0;j<=lim;j++){
				for(int k=0;k<=lim;k++){
					for(int l=0;l<=lim;l++){
						ans = max(ans, dp[j][k][l]);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}
