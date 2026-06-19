#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T;
ll n;
ll a[100009];
bool color[100009];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		ll maxn=0;
		for(ll i=0;i<=(1<<n)-1;i++){
			//cout<<"i="<<i<<endl;
			ll ans=0;
			for(ll j=1;j<=n;j++){
	
				if(i&(1<<(j-1))) color[j]=1;
				else color[j]=0;
			//	cout<<color[j]<<" ";
			}
			//cout<<endl;
			for(ll j=2;j<=n;j++){
				for(ll k=j-1;k>=1;k--){
				//	cout<<j<<' '<<k<<" ";
					if(color[k]==color[j]){
					//	cout<<"A ";
						if(a[k]==a[j]){
							ans+=a[k];
						//	cout<<a[k];
						} 
						//cout<<endl;
						break;
					} 
					
				}
			}
			if(ans>maxn){
				maxn=ans;
			//	cout<<i<<" "<<maxn<<endl;
			}
			
		}
		cout<<maxn<<endl;
	}
	return 0;
} 
