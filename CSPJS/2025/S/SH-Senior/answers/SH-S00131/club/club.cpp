#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+5;
ll t,n,a[maxn],b[maxn],c[maxn],unha[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(unha,0,sizeof(unha));
		ll acnt=0,bcnt=0,ccnt=0,ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				acnt++;
				ans+=a[i];
//				unha[i]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				bcnt++;
				ans+=b[i];
//				unha[i]=b[i]-max(a[i],c[i]);
			}
			else{
				ccnt++;
				ans+=c[i];
//				unha[i]=c[i]-max(a[i],b[i]);
			}
//			cerr<<unha[i]<<"\n";
		}
//		sort(unha+1,unha+n+1);
		ll sum=0;
		if(acnt>n/2){
			for(ll i=1;i<=n;i++)
				if(a[i]>=b[i]&&a[i]>=c[i])
					unha[++sum]=a[i]-max(b[i],c[i]);
			sort(unha+1,unha+sum+1);
			ll d=0;
			while(acnt>n/2){
				ans-=unha[++d];
				acnt--;
			}
		}
		if(bcnt>n/2){
			for(ll i=1;i<=n;i++)
				if(b[i]>=a[i]&&b[i]>=c[i])
					unha[++sum]=b[i]-max(a[i],c[i]);
			sort(unha+1,unha+sum+1);
			ll d=0;
			while(bcnt>n/2){
				ans-=unha[++d];
				bcnt--;
			}
		}
		if(ccnt>n/2){
			for(ll i=1;i<=n;i++)
				if(c[i]>=a[i]&&c[i]>=b[i])
					unha[++sum]=c[i]-max(a[i],b[i]);
			sort(unha+1,unha+sum+1);
			ll d=0;
			while(ccnt>n/2){
				ans-=unha[++d];
				ccnt--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
