#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005][4];
long long ans;
void dfs(int t,long long sum,int ra,int rb,int rc){
	if(t>n){
		if(ra<=n/2&&rb<=n/2&&rc<=n/2){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(t+1,sum+a[t][1],ra+1,rb,rc);
	dfs(t+1,sum+a[t][2],ra,rb+1,rc);
	dfs(t+1,sum+a[t][3],ra,rb,rc+1);
}
long long solve(){
	dfs(1,0,0,0,0);
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T ; cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<solve()<<'\n';
		for(int i=1;i<=n;i++){
			a[i][1]=0,a[i][2]=0,a[i][3]=0;
		}
		ans=0;
	}
	return 0;
} 
