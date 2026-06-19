#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],cnt[5],ma[N],mv[N],tot;
ll ans;
void Main(){
	cin>>n;
	ans=0;
	cnt[1]=0;
	cnt[2]=0;
	cnt[3]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
			cnt[1]++;
			ans+=a[i][1];
			ma[i]=1;
		}
		else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
			cnt[2]++;
			ans+=a[i][2];
			ma[i]=2;
		}
		else{
			cnt[3]++;
			ans+=a[i][3];
			ma[i]=3;
		}
	}
	if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
		cout<<ans<<'\n';
		return ;
	}
	else{
		ll nd=0;
		if(cnt[1]>n/2)nd=1;
		else if(cnt[2]>n/2)nd=2;
		else if(cnt[3]>n/2)nd=3;
		tot=0;
		for(int i=1;i<=n;i++){
			if(ma[i]==nd){
				int mx=0;
				for(int j=1;j<=3;j++)if(j!=nd)mx=max(mx,a[i][j]);
				mv[++tot]=a[i][nd]-mx;
			}
		}
		sort(mv+1,mv+tot+1);
		for(int i=1;i<=cnt[nd]-n/2;i++){
			ans-=mv[i];
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)Main();
	return 0;
}
