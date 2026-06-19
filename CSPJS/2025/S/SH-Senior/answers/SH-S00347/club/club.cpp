#include <bits/stdc++.h>
using namespace std;
int t,n,ans,a[100002][4];
void dfs(int dep,int sum[],int anss){
	if(dep>n){
		ans=max(ans,anss);
//		cout<<sum[1]<<' '<<sum[2]<<' '<<sum[3]<<' '<<anss<<"\n";
		return;
	}
	if(sum[1]+1<=n/2){
		sum[1]++;
		dfs(dep+1,sum,anss+a[dep][1]);
		sum[1]--;
	}
	if(sum[2]+1<=n/2){
		sum[2]++;
		dfs(dep+1,sum,anss+a[dep][2]);
		sum[2]--;
	}
	if(sum[3]+1<=n/2){
		sum[3]++;
		dfs(dep+1,sum,anss+a[dep][3]);
		sum[3]--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		int sum[4]={};
		dfs(1,sum,0);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
