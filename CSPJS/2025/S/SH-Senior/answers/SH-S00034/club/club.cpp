#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=205;
int n,a[N][3],dp[N][N][N];
void cmax(int &x,int y){
	x=(x>y?x:y); 
	return;
}
void solveA(){
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.push_back(a[i][1]);
	}
	sort(v.begin(),v.end(),greater<int>());
	int ans=0;
	for(int i=0;i<n/2;i++){
		ans+=v[i];
	}
	cout<<ans<<'\n';
	return;
}
void mian(){
	memset(dp,0,sizeof dp);
	int flagA=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j>1 and a[i][j]!=0) flagA=0;
		}
	}
	if(flagA==1){
		solveA();
		return;
	}
	for(int _=1;_<=n;_++){
		for(int i=0;i<=min(n/2,_);i++){
			for(int j=0;j<=min(n/2,_);j++){
				int k=_-i-j;
				if(k>n/2) continue;
				if(i) cmax(dp[i][j][k],dp[i-1][j][k]+a[_][1]);
				if(j) cmax(dp[i][j][k],dp[i][j-1][k]+a[_][2]);
				if(k) cmax(dp[i][j][k],dp[i][j][k-1]+a[_][3]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			int k=n-i-j;
			if(k>n/2) continue;
			ans=max(ans,dp[i][j][k]);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
}
