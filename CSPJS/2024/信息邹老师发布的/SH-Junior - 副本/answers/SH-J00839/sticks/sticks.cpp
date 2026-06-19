#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+5;
int n,t,mi;
int a[N],dp[1005][1005],a1[15]={6,2,5,0,4,5,6,3,7,0};
void dfs(int m,int ans){
	for(int i=0;i<=9;i++){
		if(m==n)mi=min(mi,ans);
		if(ans==0&&i==0||a1[i]==0)continue;
		if(m+a[i]<=n){
//			cout<<"---------"<<i<<' '<<ans<<'\n';
			dfs(m+a1[i],ans*10+i);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		mi=0x3f3f3f3f;
		cin>>n;
		if(n<2){
			cout<<-1<<'\n';
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
			cout<<'\n';
		}
		else if((n-1)%7==0){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++)
				cout<<8;
			cout<<'\n';
		}
		else {
			dfs(0,0);
			if(mi==0x3f3f3f3f||mi<0)cout<<-1;
			else cout<<mi<<'\n';
		}
	}
	return 0;
}
