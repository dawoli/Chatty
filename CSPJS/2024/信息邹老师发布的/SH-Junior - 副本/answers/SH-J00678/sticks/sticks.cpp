#include <iostream>
using namespace std;

const int INF=0x3f3f3f3f;
int n;
int lsA[100005]={0,0,1,7,4,2,6,8};
int cst[15]={6,2,5,5,4,5,6,3,7,6};
int dp[100005];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int T;
	cin >> T;
	for(int i=0;i<=100004;i++)dp[i]=INF;
	dp[0]=0;
	while(T--){
		cin >> n;
		if(dp[n]!=INF){
			cout << dp[n] << endl;
			continue;
		}
		for(int i=0;i<10;i++){
			for(int j=cst[i];j<=n;j++){
				if(i==0 && j-cst[i]==0) continue;
				dp[j]=min(dp[j],dp[j-cst[i]]*10+i);
			}
		}
		if(dp[n]==INF){
			cout << -1 << endl;
		}else{
			cout << dp[n] << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

