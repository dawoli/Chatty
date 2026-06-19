#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int t,n,u;
struct peop{
	int val[4],ap;
} p[N];
int dlt[N],ndlt;
int cntap[4];
void solve(){
	for(int i=1;i<=3;i++) cntap[i]=0;
	ndlt=0;
	u=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].val[1]>>p[i].val[2]>>p[i].val[3];
		p[i].ap=(p[i].val[1]>=p[i].val[2]&&p[i].val[1]>=p[i].val[3]?1:
		(p[i].val[2]>=p[i].val[3]?2:3));
		cntap[p[i].ap]++;
	}
	if(cntap[1]>n/2) u=1;
	else if(cntap[2]>n/2) u=2;
	else if(cntap[3]>n/2) u=3;
	int ans=0;
	for(int i=1;i<=n;i++) ans+=p[i].val[p[i].ap];
	ndlt=0;
	if(u!=0){
		for(int i=1;i<=n;i++) if(p[i].ap==u){
			if(u==1) dlt[++ndlt]=p[i].val[1]-max(p[i].val[2],p[i].val[3]);
			if(u==2) dlt[++ndlt]=p[i].val[2]-max(p[i].val[1],p[i].val[3]);
			if(u==3) dlt[++ndlt]=p[i].val[3]-max(p[i].val[2],p[i].val[1]);
		}
		sort(dlt+1,dlt+1+ndlt);
		for(int i=1;i<=ndlt-n/2;i++) ans-=dlt[i];
	}
	cout<<ans<<"\n";
	return;
	
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}

