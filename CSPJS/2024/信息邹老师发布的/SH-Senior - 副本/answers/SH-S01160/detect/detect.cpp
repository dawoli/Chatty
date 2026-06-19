#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e5+10;
ll a[biao],b[biao][3];

struct wei{
	ll x,y;
};

wei rd[biao];

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	ll t;
	cin>>t;
	
	while(t--){
		ll n,m,l,v;
		cin>>n>>m>>l>>v;
		
		for(ll i=1;i<=n;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
		
		for(ll i=1;i<=m;i++) cin>>a[i];
		
		ll ans=0;
		for(ll i=1;i<=n;i++){
			rd[i].x=0,rd[i].y=0;
			if(b[i][2]>0){
				double v0=b[i][1];
				double d=(v*v-v0*v0)/(2*b[i][2]);
				
				double aim=b[i][0]+max(0.0,d);
				//cout<<i<<" "<<aim<<endl;
				if(aim>l) continue;
				
				ll le=0,ri=m+1;
				while(le+1<ri){
					ll mid=le+(ri-le)/2;
					if(a[mid]>aim) ri=mid;
					else le=mid;
				}
				
				if(ri>m) continue;
				ans++;
				rd[i].x=ri,rd[i].y=m;
			}
			else if(!b[i][2]){
				if(b[i][1]<=v) continue;
				
				ll le=0,ri=m+1;
				while(le+1<ri){
					ll mid=le+(ri-le)/2;
					if(a[mid]>=b[i][0]) ri=mid;
					else le=mid;
				}
				
				if(ri>m) continue;
				ans++;
				rd[i].x=ri,rd[i].y=m;
			}
			else{
				ll v0=b[i][1];
				if(v0<v) continue;
				
				double d=(v*v-v0*v0)/(2*b[i][2]);
				
				double aim=b[i][0]+d;
				
				//cout<<i<<" "<<aim<<endl;
				
				ll le=0,ri=m+1;
				while(le+1<ri){
					ll mid=le+(ri-le)/2;
					if(a[mid]<aim) le=mid;
					else ri=mid;
				}
				
				ll l1=0,l2=m+1;
				while(l1+1<l2){
					ll mid=l1+(l2-l1)/2;
					if(a[mid]<b[i][0]) l1=mid;
					else l2=mid;
				}
				
				if(l2>le) continue;
				ans++;
				rd[i].x=l2,rd[i].y=le;
			}
		}
		
		/*for(ll i=1;i<=n;i++){
			for(ll j=0;j<rd[i].size();j++){
				cout<<rd[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
		cout<<ans<<endl;
	}
	
	return 0;
}
