#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=100009;
ll t,n,m;
ld L,V,d[N],v[N],a[N],p[N];
void solveyunsu(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(v[i]>V && d[i]<=p[m]){
			ans++;
		}
	}
	cout<<ans<<' ';
	if(ans==0){
		cout<<m<<endl;
	}else{
		cout<<m-1<<endl;
	}
}
void solvejiasu(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(ld(sqrt(v[i]*v[i]+2*a[i]*p[m]-d[m]))>V && d[i]<=L){
			ans++;
		}
	}
	cout<<ans<<' ';
	if(ans==0){
		cout<<m<<endl;
	}else{
		cout<<m-1<<endl;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	ld maxa=-INT_MAX,mina=INT_MAX;
	for(ll u=1;u<=t;u++){
		cin>>n>>m>>L>>V;
		for(ll i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			maxa=max(maxa,a[i]);
			mina=min(mina,a[i]);
		}
		for(ll i=1;i<=m;i++){
			cin>>p[i];
		}
		if(maxa==0 && mina==0){
			solveyunsu();
		}else if(mina>0){
			solvejiasu();
		}else{
			cout<<n<<' '<<0<<endl;
		}
	}
	return 0;
}
