#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n,m,L,V;
ll d[100005];
ll v[100005];
ll a[100005];
ll p[100005];
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
		}
		bool A=1,B=1,C=1;
		for(ll i=1;i<=n;i++){
			if(a[i]>0) C=A=0;
			if(a[i]==0) C=B=0;
			if(a[i]<0) A=B=0;
		}
		if(A==1){
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(d[i]<=p[m]&&v[i]>V){
					cnt++;
				}
			}
			if(cnt!=0) cout<<cnt<<" "<<m-1<<endl;
			else cout<<cnt<<" "<<m<<endl;
		}
		if(B==1){
			ll cnt=0;
			for(ll i=1;i<=n;i++){
				if(v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V) cnt++;
			}
			cout<<cnt<<" ";
			if(cnt!=0) cout<<m-1<<endl;
			else cout<<m<<endl;
		}
	}
} 
