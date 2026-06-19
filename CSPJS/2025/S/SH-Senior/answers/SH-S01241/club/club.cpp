#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
const int N=1e5+5;
int n,a[N],b[N],c[N];
bool vis[N],vis2[N];
int solve(int op){
	memset(vis,0,sizeof(vis));
	memset(vis2,0,sizeof(vis2));
	
	priority_queue<pii,vector<pii > ,less<pii > >q;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(op==1){
			ans+=a[i];q.push(make_pair(b[i]-a[i],i));
		q.push(make_pair(c[i]-a[i],i));
		}
		if(op==2){
			ans+=b[i];
			q.push(make_pair(c[i]-b[i],i));
		q.push(make_pair(a[i]-b[i],i));
		}
		
	}
	int cnt[4];
	cnt[1]=cnt[2]=cnt[3]=0;
	cnt[op]=n;
	while(!q.empty()){
		pii x=q.top();
		q.pop();
		int id=x.se,val=x.fi,k=3;
		if(val==b[id]-a[id]&&vis2[id]==0)k=2,vis2[id]=1;
		if(k==op)k=1;
		//cout<<id<<' '<<k<<' '<<val<<'\n';
		if(vis[id]){
			continue;
		}
		else{
			vis[id]=1;
			if(val<=0){
				if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)break;
				if(cnt[1]>=n/2){
					ans+=val;
					cnt[op]--;
					cnt[k]++;
				}
				else{
					vis[id]=0;
				}
			}
			else{
				if(cnt[k]<n/2){
					ans+=val;
					cnt[k]++;
					cnt[op]--;
					//cout<<id<<' '<<k<<' '<<val<<' '<<ans<<'\n';
				}
				else{
					vis[id]=0;
				}
			}
		}
	}
	//for(int i=1;i<=3;i++)cout<<cnt[i]<<' ';
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int ans1=solve(1);
		int ans2=solve(2);
		cout<<max(ans1,ans2)<<'\n';
	}
	return 0;
} 
