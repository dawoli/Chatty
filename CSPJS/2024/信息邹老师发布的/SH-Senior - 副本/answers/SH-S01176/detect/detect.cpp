#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,L,V,d[100005],v[100005],a[100005],l[100005],r[100005],k,p[100005],cnt[100005],ans1,ans2;
vector<ll> rng[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
    	fill(cnt+1,cnt+100005,0);
    	for(ll i=1;i<=100000;i++){
    		rng[i].clear();
		}
    	ans1=ans2=0;
        cin>>n>>m>>L>>V;
        k=0;
        for(ll i=1;i<=n;i++){
        	cin>>d[i]>>v[i]>>a[i];
        	if(a[i]==0){
        		if(v[i]>V){
        			k++;
        			l[k]=d[i];
        			r[k]=L;
				}
			}
			else if(a[i]>0){
        		if(v[i]>V){
        			k++;
        			l[k]=d[i];
        			r[k]=L;
				}
				else if(d[i]+(ll)ceil((V*V-v[i]*v[i])/2.0/a[i])<L){
					k++;
					l[k]=d[i]+(ll)floor((V*V-v[i]*v[i])/2.0/a[i]+1);
					r[k]=L;
				}
			}
			else{
				if(v[i]>V){
					k++;
					l[k]=d[i];
					r[k]=min(L,d[i]+(ll)ceil((v[i]*v[i]-V*V)/2.0/(-a[i])-1));
				}
			}
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		for(ll i=1;i<=k;i++){
			//cout<<l[i]<<" "<<r[i]<<endl;
			ll x=lower_bound(p+1,p+m+1,l[i])-p;
			ll y=upper_bound(p+1,p+m+1,r[i])-p;
			cnt[i]=y-x;
			if(cnt[i]){
				ans1++;
			}
			for(ll j=x;j<y;j++){
				rng[j].push_back(i);
			}
		}
		for(ll i=1;i<=m;i++){
			ll ok=1;
			for(ll j=0;j<rng[i].size();j++){
				if(cnt[rng[i][j]]<=1){
					ok=0;
					break;
				}
			}
			if(ok){
				for(ll j=0;j<rng[i].size();j++){
				    cnt[rng[i][j]]--;
			    }
			    ans2++;
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
    return 0;
}

