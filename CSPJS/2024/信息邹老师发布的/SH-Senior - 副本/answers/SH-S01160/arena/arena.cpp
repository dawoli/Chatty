#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e5+10;
ll ap[biao],c[biao],a[biao];
string s[20];
ll n,m;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>ap[i];
	for(ll i=1;i<=m;i++) cin>>c[i];
	
	ll l=log2(n);
	if((1<<l)<n) l++;
	
	for(ll i=1;i<=l;i++) cin>>s[i]; 
	
	ll t;
	cin>>t;
	
	while(t--){
		ll x[4]={0};
		for(ll i=0;i<4;i++) cin>>x[i];
		
		for(ll i=1;i<=n;i++) a[i]=ap[i]^x[i%4];
		//for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		//cout<<endl;
		
		ll ans=0;
		vector<ll> v;
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=c[i];j++) v.push_back(j);
			
			for(ll j=1;j<=log2(c[i]);j++){
				ll si=v.size();
				vector<ll> nxt;
				//cout<<si<<endl;
				
				for(ll k=0;k<si;k+=2){
					ll x1=v[k],x2=v[k+1];
					//cout<<s[j][k/2];
					if(s[j][k/2]=='0'){
						if(a[min(x1,x2)]>=j) nxt.push_back(min(x1,x2));
						else nxt.push_back(max(x1,x2));
					}
					else{
						if(a[max(x1,x2)]>=j) nxt.push_back(max(x1,x2));
						else nxt.push_back(min(x1,x2));
					}
				}
				//cout<<endl;
				
				v=nxt;
			}
			
		//	cout<<v[0]<<" "<<(i*v[0])<<" "<<v.size()<<endl;
			ans^=(i*v[0]);
			v.pop_back();
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
