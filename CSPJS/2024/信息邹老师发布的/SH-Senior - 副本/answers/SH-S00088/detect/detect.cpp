#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100009
ll T,n,m,l,V,d[N],v[N],a[N],p[N],ans,ans2;
bool ok[29];
void dfs(ll i,ll cnt){
	if(cnt>=ans2)return;
	if(i==m+1){
		ll res=0;
		for(ll i=1;i<=n;i++){
		    for(ll j=1;j<=m;j++){
			    if(p[j]<d[i]||!ok[j])continue;
			    if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){
				    res++;
				    break;
			    }
		    }
	    }
	    if(res==ans)ans2=min(ans2,cnt);
	    return;
	}
	ok[i]=1;
	dfs(i+1,cnt+1);
	ok[i]=0;
	dfs(i+1,cnt);
}
void solbf(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(p[j]<d[i])continue;
			if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<" ";
	dfs(1,0);
	cout<<m-ans2<<"\n";
}
ll lb(ll l1,ll r1,ll s1){
	ll ans=r1;
	while(l1<=r1){
		ll mid=l1+(r1-l1)/2;
		if(p[mid]>=s1)ans=mid,r1=mid-1;
		else l1=mid+1;
	}
	return ans;
}
bool alla0(){
	for(ll i=1;i<=n;i++)if(a[i]!=0)return 0;
	return 1;
}
void sola0(){
	for(ll i=1;i<=n;i++){
		if(v[i]>V&&d[i]<=p[m])ans++;
	}
	cout<<ans<<" "<<(ans==0?m:m-1)<<"\n";
}
bool allba0(){
	for(ll i=1;i<=n;i++)if(a[i]<=0)return 0;
	return 1;
}
void solba0(){
	for(ll i=1;i<=n;i++){
		if(d[i]<=p[m]&&2*a[i]*p[m]>V*V+2*a[i]*d[i]-v[i]*v[i])ans++; 
	}
	cout<<ans<<" "<<(ans==0?m:m-1)<<"\n";
}
bool allsa0(){
	for(ll i=1;i<=n;i++)if(a[i]>=0)return 0;
	return 1;
}
struct seg{
	ll l,r;
}sg[N];
ll nseg;
bool cmp(seg ax,seg ay){
	return ax.r<ay.r;
}
void solsa0(){
	nseg=0;
	for(ll i=1;i<=n;i++){
		ll q=2*a[i],z=V*V+2*a[i]*d[i]-v[i]*v[i];
		if(z>0)continue;
		ll it=lb(1,m,d[i]);
		ll u1=p[it],u2=it;
		if(q*u1>z){
			ans++;
			sg[++nseg].l=u2;
			ll lp=u2,rp=m,ansr=u2;
			while(lp<=rp){
				ll mid=lp+(rp-lp)/2;
				if(q*p[mid]>z)ansr=mid,lp=mid+1;
				else rp=mid-1;
			}
			sg[nseg].r=ansr;
		}
	}
//	for(ll i=1;i<=n;i++)cout<<i<<":"<<sg[i].l<<" "<<sg[i].r<<"\n";
    sort(sg+1,sg+1+nseg,cmp);
    ll ra=0,cntx=0;
    for(ll i=1;i<=nseg;i++){
    	if(ra<sg[i].l)cntx++,ra=sg[i].r;
	}
	cout<<ans<<" ";
	cout<<m-cntx<<"\n"; 
}
void sol(){
	nseg=0;
	for(ll i=1;i<=n;i++){
		if(a[i]==0){
			if(v[i]>V&&d[i]<=p[m]){
				ans++;
				ll it=lb(1,m,d[i]);
		        ll u1=p[it],u2=it;
				sg[++nseg].l=u2;
				sg[nseg].r=m;
			}
		}
		else if(a[i]>0){
			ll q=2*a[i],z=V*V+2*a[i]*d[i]-v[i]*v[i];
			if(d[i]<=p[m]&&q*p[m]>z){
				ans++;
				sg[++nseg].r=m;
				ll it=lb(1,m,d[i]);
		        ll u1=p[it],u2=it;
				ll lp=u2,rp=m,ansl=m;
				while(lp<=rp){
					ll mid=lp+(rp-lp)/2;
					if(q*p[mid]>z)ansl=mid,rp=mid-1;
					else lp=mid+1;
				}
				sg[nseg].l=ansl;
//				if(T==0)cout<<"l:"<<sg[nseg].l<<" "<<sg[nseg].r<<"\n";
			}
		}
		else{
			ll q=2*a[i],z=V*V+2*a[i]*d[i]-v[i]*v[i];
			if(z>0)continue;
			ll it=lb(1,m,d[i]);
		    ll u1=p[it],u2=it;
			if(q*u1>z){
				ans++;
				sg[++nseg].l=u2;
				ll lp=u2,rp=m,ansr=u2;
				while(lp<=rp){
					ll mid=lp+(rp-lp)/2;
					if(q*p[mid]>z)ansr=mid,lp=mid+1;
					else rp=mid-1;
				}
				sg[nseg].r=ansr;
//				if(T==0)cout<<"r:"<<sg[nseg].l<<" "<<sg[nseg].r<<"\n";
			}
		}
	}
	sort(sg+1,sg+1+nseg,cmp);
    ll ra=0,cntx=0;
//    if(T==0)cout<<nseg<<"\n";
    for(ll i=1;i<=nseg;i++){
//    	if(T==0)cout<<i<<":"<<sg[i].l<<" "<<sg[i].r<<"\n";
    	if(ra<sg[i].l)cntx++,ra=sg[i].r;
	}
	cout<<ans<<" ";
	cout<<m-cntx<<"\n"; 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>V;
		ans=0;
		ans2=m;
		for(ll i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(ll i=1;i<=m;i++)cin>>p[i];
		if(n<=10&&m<=10)solbf();
		else if(alla0())sola0();
		else if(allba0())solba0();
		else if(allsa0())solsa0();
		else sol();
	}
	return 0;
}
