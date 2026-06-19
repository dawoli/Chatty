#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,n;
struct stu{
	ll x,y,z;
	ll fst,snd,lst;
}a[N];
bool cmp(const stu&p,const stu&q){
	if(p.lst>q.lst){
		return false;
	}else if(p.lst<q.lst){
		return true;
	}else if(p.snd>q.snd){
		return false;
	}else if(p.snd<q.snd){
		return true;
	}else{
		return (p.fst>q.fst);
	}
}
void input(){
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i].x);
		scanf("%lld",&a[i].y);
		scanf("%lld",&a[i].z);
		if(a[i].x>=a[i].y && a[i].x>=a[i].z){
			a[i].fst=a[i].x;
			if(a[i].y>=a[i].z){
				a[i].snd=a[i].y;
				a[i].lst=a[i].z;
			}else{
				a[i].snd=a[i].z;
				a[i].lst=a[i].y;
			}
		}else if(a[i].x<=a[i].y && a[i].y>=a[i].z){
			a[i].fst=a[i].y;
			if(a[i].x>=a[i].z){
				a[i].snd=a[i].x;
				a[i].lst=a[i].z;
			}else{
				a[i].snd=a[i].z;
				a[i].lst=a[i].x;
			}
		}else{
			a[i].fst=a[i].z;
			if(a[i].y>=a[i].x){
				a[i].snd=a[i].y;
				a[i].lst=a[i].x;
			}else{
				a[i].snd=a[i].x;
				a[i].lst=a[i].y;
			}
		}
	}
	return;
}
void solve(){
	sort(a+1,a+1+n,cmp);
	ll cntx=0,cnty=0,cntz=0;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(a[i].x>a[i].y && a[i].x>a[i].z){
			if(cntx<(n/2)){
				cntx++;
				ans+=a[i].x;
			}else{
				if(a[i].y>a[i].z){
					cnty++;
					ans+=a[i].y;
				}else{
					cntz++;
					ans+=a[i].z;
				}
			}
		}else if(a[i].y>a[i].x && a[i].y>a[i].z){
			if(cnty<(n/2)){
				cnty++;
				ans+=a[i].y;
			}else{
				if(a[i].x>a[i].z){
					cntx++;
					ans+=a[i].x;
				}else{
					cntz++;
					ans+=a[i].z;
				}
			}
		}else if(a[i].z>a[i].y && a[i].z>a[i].y){
			if(cntz<(n/2)){
				cntz++;
				ans+=a[i].z;
			}else{
				if(a[i].y>a[i].x){
					cnty++;
					ans+=a[i].y;
				}else{
					cntx++;
					ans+=a[i].x;
				}
			}
		}else if(a[i].x==a[i].y && a[i].x!=a[i].z){
			if(cntx<=cnty && cntx<(n/2)){
				cntx++;
				ans+=a[i].x;
			}else if(cnty<(n/2)){
				cnty++;
				ans+=a[i].y;
			}else{
				cntz++;
				ans+=a[i].z;
			}
		}else if(a[i].z==a[i].y && a[i].x!=a[i].z){
			if(cntz<=cnty && cntz<(n/2)){
				cntz++;
				ans+=a[i].z;
			}else if(cnty<(n/2)){
				cnty++;
				ans+=a[i].y;
			}else{
				cntx++;
				ans+=a[i].x;
			}
		}else if(a[i].x==a[i].z && a[i].x!=a[i].y){
			if(cntx<=cntz && cntx<(n/2)){
				cntx++;
				ans+=a[i].x;
			}else if(cntz<(n/2)){
				cntz++;
				ans+=a[i].z;
			}else{
				cnty++;
				ans+=a[i].y;
			}
		}else{
			if(cntx<=cnty && cntx<=cntz && cntx<(n/2)){
				cntx++;
				ans+=a[i].x;
			}else if(cnty<=cntx && cnty<=cntz && cnty<(n/2)){
				cnty++;
				ans+=a[i].y;
			}else{
				cntz++;
				ans+=a[i].z;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(ll pigeon=1;pigeon<=T;pigeon++){
		input();
		solve();
	}
	return 0;
} 
