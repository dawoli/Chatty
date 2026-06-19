#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll T,n;
ll maxn(ll x,ll y){
	return x>y?x:y;
}
ll minn(ll x,ll y){
	return x<y?x:y;
}
struct Node{
	ll x,y,z;
	ll fir,sec,thi;
	bool operator<(const Node &t) const{
		if(fir-sec==t.fir-t.sec){
			if(sec-thi==t.sec-thi){
				return thi>t.thi;
			}
			return sec-thi>t.sec-t.thi;
		}
		return fir-sec>t.fir-t.sec;
	}
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			ll x,y,z;
			cin>>x>>y>>z;
			a[i].x=x;
			a[i].y=y;
			a[i].z=z;
			ll lns1=maxn(x,y),lns2=minn(x,y);
			if(z>lns1){
				a[i].fir=z;
				a[i].sec=lns1;
				a[i].thi=lns2;
			}else if(z<lns2){
				a[i].fir=lns1;
				a[i].sec=lns2;
				a[i].thi=z;
			}else{
				a[i].fir=lns1;
				a[i].sec=z;
				a[i].thi=lns2;
			}
		}
		sort(a+1,a+n+1);
		ll ji1=0,ji2=0,ji3=0,ans=0;
		for(ll i=1;i<=n;i++){
			if(a[i].x>a[i].y){
				if(a[i].x>a[i].z){
					if(ji1==n/2){
						if(a[i].y>a[i].z){
							ans+=a[i].y;
							ji2++;
						}else{
							ans+=a[i].z;
							ji3++;
						}
					}else{
						ans+=a[i].x;
						ji1++; 
					}
				}else{
					if(ji3==n/2){
						ans+=a[i].x;
						ji1++;
					}else{
						ans+=a[i].z;
						ji3++;
					}
				}
			}else{
				if(a[i].y>a[i].z){
					if(ji2==n/2){
						if(a[i].x>a[i].z){
							ans+=a[i].x;
							ji1++;
						}else{
							ans+=a[i].z;
							ji3++;
						}
					}else{
						ans+=a[i].y;
						ji2++;
					}
				}else{
					if(ji3==n/2){
						ans+=a[i].y;
						ji2++;
					}else{
						ans+=a[i].z;
						ji3++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
