#include<bits/stdc++.h> //I fuck CCF 
//#define int long long //我要上迷惑行为大赏 
using namespace std;
const int N=201;
int t;
int n;
int a[100001][4];
int dp[2][N][N][N];
int ans;
bool A=true;//特殊数据 
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n;
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j!=1){
				if(a[i][j])A=false;
			}
		}
	}if(A){
		vector<int>p;
		for(int i=1;i<=n;i++){
			p.push_back(a[i][1]);
		}sort(p.begin(),p.end(),cmp);
		for(int i=0;i<n/2;i++){
			ans+=p[i];
		}
	}else if(n<=200){
		for(int j=1;j<=n;j++){
			int i=j&1;
			for(int x=0;x<=j&&x<=n/2;x++){
				for(int y=0;x+y<=j&&y<=n/2;y++){
					int z=j-x-y;
					if(z>n/2)continue;
					if(x)dp[i][x][y][z]=max(dp[i][x][y][z],dp[i^1][x-1][y][z]+a[j][1]);
					if(y)dp[i][x][y][z]=max(dp[i][x][y][z],dp[i^1][x][y-1][z]+a[j][2]);
					if(z)dp[i][x][y][z]=max(dp[i][x][y][z],dp[i^1][x][y][z-1]+a[j][3]);
				}
			}
		}for(int x=0;x<=n/2;x++){
			for(int y=0;x+y<=n&&y<=n/2;y++){
				int z=n-x-y;
				if(z>n/2)continue;
				ans=max(ans,dp[n&1][x][y][z]);
			}
		}
	}else{
		ans=0;
	}cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
3 
4
4 2 1
3 2 4 
5 3 4 
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
