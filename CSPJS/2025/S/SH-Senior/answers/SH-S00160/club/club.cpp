#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
int n,m;
int a[N][6];
int dp[N][N/2][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int w = n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			ans = max(a[i][1],ans);
		}
		cout<<ans;
	}
	return 0;
}

