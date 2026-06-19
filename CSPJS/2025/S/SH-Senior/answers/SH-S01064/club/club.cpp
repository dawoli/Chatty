#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll a[4][N],maxa[N],cnt[4],arr[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll q;
    cin>>q;
    while(q--){
    	memset(maxa,0,sizeof(maxa));
    	memset(a,0,sizeof(a));
    	memset(cnt,0,sizeof(cnt));
    	memset(arr,0,sizeof(arr));
 	   	ll n;
	    cin>>n;
	    for(ll i = 1;i <= n;i++){
	        cin>>a[1][i]>>a[2][i]>>a[3][i];
	        for(ll j = 1;j <= 3;j++){
	            if(a[j][i]>a[maxa[i]][i])maxa[i]=j;
	        }
	    }
	    for(ll i = 1;i <= n;i++)cnt[maxa[i]]++;
	    ll ans=0;
	    for(ll i = 1;i <= n;i++)ans+=a[maxa[i]][i];
	    if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
	        cout<<ans;
	    }
	    else{
	        ll maxcnt=0,np=0;
	        for(ll j = 1;j <= 3;j++){
	            if(cnt[j]>n/2){
	                maxcnt=j;
	                break;
	            }
	        }
	        ll todel=cnt[maxcnt]-n/2;
	        for(ll i = 1;i <= n;i++){
	            if(maxa[i]==maxcnt){
	                ll mcost=5.2e17;
	                for(ll j = 1;j <= 3;j++){
	                    if(j==maxa[i])continue;
	                    mcost=min(mcost,a[maxa[i]][i]-a[j][i]);
	                }
	                arr[++np]=mcost;
	            }
	        }
	        sort(arr+1,arr+np+1);
	        for(ll i = 1;i <= todel;i++){
	            ans-=arr[i];
	        }
	        cout<<ans;
	    }
	    cout<<'\n';
	}
    return 0;
}
