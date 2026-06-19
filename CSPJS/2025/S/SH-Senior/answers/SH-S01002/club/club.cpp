#include <bits/stdc++.h>
using namespace std;
int T,n;
int p[100005][4];
long long ans = 0;
long long sum = 0;
void dfs(int i,int a,int b,int c){
	if(i == n+1){
		ans= max(ans,sum);
		return;
	} 
	if(a -1>= 0){
		sum += p[i][1];
		dfs(i+1,a-1,b,c);
		sum -= p[i][1];
	} 
	if(b -1>= 0) {
		sum += p[i][2];
		dfs(i+1,a,b-1,c);
		sum -= p[i][2];
	}
	if(c -1>= 0){
		sum += p[i][3];
		dfs(i+1,a,b,c-1);
		sum -= p[i][3];
	} 
}
bool cmp(int a,int b){
	return a > b;
}
struct Node{
	int sum,a,b,c;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin >> T;
	while(T){
		T--; 
		cin >> n;
		ans = 0;sum= 0;
		bool fl = true;
		for(int i = 1;i<=n;i++) memset(p[i],0,sizeof(p[i]));
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=3;j++) {
				cin >> p[i][j]; 
				if(j > 1 && p[i][j] !=0) fl = false;
			}
		}
		
		if(n <= 10){
			dfs(1,n/2,n/2,n/2);
			cout<< ans << endl;
			continue;
		}
		
		else if(fl){
			int tp[100005];
			for(int i = 1;i<=n;i++) tp[i] = p[i][1];
			sort(tp+1,tp+1+n,cmp );
			for(int i = 1;i<=n/2;i++) ans += tp[i];
			cout<< ans << endl;
			continue;
		}
		else if(n <= 30){
			Node dp[32][4];//1,2,3 
			dp[1][1] = (Node){p[1][1],n/2 -1,n/2,n/2};
			dp[1][2] = (Node){p[1][2],n/2 ,n/2-1,n/2};
			dp[1][3] = (Node){p[1][3],n/2 ,n/2,n/2-1};
			for(int i = 2;i<=n;i++){
				// Get a 
				if(dp[i-1][1].a >= 1)
					dp[i][1] = (Node){max(dp[i][1].sum,dp[i-1][1].sum + p[i][1]),n/2 -1,n/2,n/2};
			}
			cout << ans<< endl;
			continue;
		}
		
	}
	
	return 0;
} 
