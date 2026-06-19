#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
const ll N=100009;
ll a[N],l[N],r[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		fill(l+1,l+N+1,0);
		fill(r+1,r+N+1,0);
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ll maxx=*max_element(a+1,a+1+n);
		ll ans=0;
		while(1){
			maxx=*max_element(a+1,a+1+n);
		 	//cout<<"maxx="<<maxx<<endl;
			if(maxx==-1) break;
			for(ll i=1;i<=n;i++){
				if(a[i]==maxx){ l[1]=i; break;}
			}
			for(ll i=n;i>=1;i--){
				if(a[i]==maxx){ r[1]=i; break;}
			} 
			//cout<<l<<" "<<r<<endl;
			if(l[1]==r[1]) a[l[1]]=-1;
			else {a[l[1]]=-1; a[r[1]]=-1; ans+=maxx; break;}
		}
		//cout<<"ans="<<ans<<endl;
		ll L=0,R=n,cnt=0;
		while(1){
			maxx=*max_element(a+1,a+1+n);
			if(maxx==-1) break;
			//if(maxx==2) break;
			for(ll i=1;i<=n;i++){
				if(a[i]==maxx){ l[++cnt]=i; break;}
			}
			for(ll i=n;i>=1;i--){
				if(a[i]==maxx){ r[++cnt]=i;break;}
			}
			//cout<<L<<" "<<R<<endl;
			//if(maxx==2) break;
			if(l[cnt]==r[cnt]){
				a[l[cnt]]=-1;
				a[l[cnt]]=-1;
				cnt--;
				continue;
			}
			bool fl=0;
			for(ll i=1;i<=cnt-1;i++){
				if(l[cnt]>l[i]&&r[cnt]<r[i]){
					a[l[cnt]]=-1;
					a[r[cnt]]=-1;
					cnt--;
					fl=1;
					break;
				}
			}
			if(fl==1) continue;
			else{
				ans+=maxx;
				a[L]=-1;
				a[R]=-1;
			} 
			//cout<<"ans="<<ans<<endl;
		}
		//cout<<"ans="<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}

