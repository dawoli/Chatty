#include <bits/stdc++.h>
using namespace std;
long long dp[100005][2],ans;
int a[100005],t,n;
bool c[100005];

void solve1(long long csum, int i,int lastr, int lastb){
	if(i>n){
		ans=max(ans,csum);
		return;
	}
	int temp1=0,temp2=0;
	if(lastr==a[i])temp1=a[i];
	if(lastb==a[i])temp2=a[i];
	//red
	solve1(csum+temp1,i+1,a[i],lastb);
	//blue
	solve1(csum+temp2,i+1,lastr,a[i]);
	return;
}



int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		solve1(0,1,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
