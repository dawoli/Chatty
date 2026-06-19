#include<bits/stdc++.h>
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
#define ll long long
using namespace std;
const int N=100050;
int n;
ll a[N][3]; 
ll ans;
int clb[N];
ll chng[N];
ll mmb0[N],mmb1[N],mmb2[N]; int cnt[3];

inline bool cmp(int x,int y) { return chng[x]<chng[y]; }

int main() {
	FILE("club");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=0;i<n;i++) {
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ll mx=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=mx;
			if(a[i][0]==mx) { clb[i]=0; mmb0[cnt[0]++]=i; }
			if(a[i][1]==mx) { clb[i]=1; mmb1[cnt[1]++]=i; }
			if(a[i][2]==mx) { clb[i]=2; mmb2[cnt[2]++]=i; }
			int k=clb[i];
			chng[i]=min(a[i][k]-a[i][k==2?0:k+1],a[i][k]-a[i][k==0?2:k-1]);
		}
//			for(int i=0;i<n;i++) cout<<clb[i]<<" "; cout<<"\n"; //ต๗สิ 
//			for(int i=0;i<n;i++) cout<<chng[i]<<" "; cout<<"\n"; //ต๗สิ 
//			for(int i=0;i<cnt[0];i++) cout<<mmb0[i]<<" "; cout<<"\n"; //ต๗สิ 
		ll dec=0;
		if(cnt[0]>n/2) {
			sort(mmb0,mmb0+cnt[0],cmp);
			for(int i=0;i<cnt[0]-(n/2);i++) dec+=chng[mmb0[i]];
		}
		else if(cnt[1]>n/2) {
			sort(mmb1,mmb1+cnt[1],cmp);
			for(int i=0;i<cnt[1]-(n/2);i++) dec+=chng[mmb1[i]];
		}
		else if(cnt[2]>n/2) {
			sort(mmb2,mmb2+cnt[2],cmp);
			for(int i=0;i<cnt[2]-(n/2);i++) dec+=chng[mmb2[i]];
		}
		cout<<ans-dec<<"\n";
	}
	return 0;
}
