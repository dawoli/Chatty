#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
int cnt[4];
int ans;
void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		cnt[i]++;
		if(cnt[i]>n/2){
			cnt[i]--;
			continue;
		}
		dfs(k+1,sum+a[k][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=0;
		if(n<30){
			dfs(1,0);
			cout<<ans<<endl;
		}
		else{
			int _n=n/2;
			sort(a[1]+1,a[1]+1+n);
			for(int i=n;i>=n-_n+1;i--){
				ans+=a[i][1];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
