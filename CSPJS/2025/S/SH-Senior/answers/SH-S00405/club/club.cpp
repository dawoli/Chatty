#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 0x3f3f3f3f;
const int N = 1e5+5;
int n,t;
int a[N][4];
int dp[N][4];

int dfs(int k,int x,int y,int z,int sum){
	if(k==n) return sum;
	int xx,yy,zz;
	(x < lim) ? xx = dfs(k+1,x+1,y,z,sum+a[k+1][1]) : xx=0;
	(y < lim) ? yy = dfs(k+1,x,y+1,z,sum+a[k+1][2]) : yy=0;
	(z < lim) ? zz = dfs(k+1,x,y,z+1,sum+a[k+1][3]) : zz=0;
	return max({xx,yy,zz});
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		lim = n/2;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		
		cout<<dfs(0,0,0,0,0)<<endl;
	}
	return 0;
}
