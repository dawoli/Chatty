#include<bits/stdc++.h>
#define ll long long
#define a first
#define b second
ll t,n;
ll a[100010][10];
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		cin >> n;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		ll cnt1=0,cnt2=0,cnt3=0;
		ll sum=0;
		for(ll i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				cnt1++;
				sum+=a[i][1];
				a[i][2]-=a[i][1];
				a[i][3]-=a[i][1];
				a[i][1]=0;
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				cnt2++;
				sum+=a[i][2];
				a[i][1]-=a[i][2];
				a[i][3]-=a[i][2];
				a[i][2]=0;
			}
			else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
				cnt3++;
				sum+=a[i][3];
				a[i][1]-=a[i][3];
				a[i][2]-=a[i][3];
				a[i][3]=0;
			}
		}
		if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2){
			cout << sum << endl; 
		}
		else{
			if(cnt1>n/2){
				priority_queue<pair<ll,ll> >pq;
				for(ll i=1;i<=n;i++){
					if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
						pq.push({max(a[i][2]-a[i][1],a[i][3]-a[i][1]),min(a[i][2]-a[i][1],a[i][3]-a[i][1])});
					}
				}
				for(ll i=1;i<=cnt1-n/2;i++){
					sum+=pq.top().a;
					pq.pop();
				}
			}
			else if(cnt2>n/2){
				priority_queue<pair<ll,ll> >pq;
				for(ll i=1;i<=n;i++){
					if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
						pq.push({max(a[i][1]-a[i][2],a[i][3]-a[i][2]),min(a[i][1]-a[i][2],a[i][3]-a[i][2])});
					}
				}
				for(ll i=1;i<=cnt2-n/2;i++){
					sum+=pq.top().a;
					pq.pop();
				}
			}
			else if(cnt3>n/2){
				priority_queue<pair<ll,ll> >pq;
				for(ll i=1;i<=n;i++){
					if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
						pq.push({max(a[i][1]-a[i][3],a[i][2]-a[i][3]),min(a[i][1]-a[i][3],a[i][2]-a[i][3])});
					}
				}
				for(ll i=1;i<=cnt3-n/2;i++){
					sum+=pq.top().a;
					pq.pop();
				}
			}
			cout << sum << endl;
		}
	}
	
	
	
	
	
	
	return 0;
} 
