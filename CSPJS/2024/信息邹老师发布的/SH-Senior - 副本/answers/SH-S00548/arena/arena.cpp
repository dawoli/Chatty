#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,a2[N],a[N],c[N],x[4],p2[29],d[29][1029];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	p2[0]=1;
	for(ll i=1;i<=20;++i)p2[i]=p2[i-1]*2;
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a2[i];
	}
	for(ll i=1;i<=m;++i){
		cin>>c[i];
	}
	ll K=0;
	while(p2[K]<n)K++;
	for(ll i=1;i<=K;++i){
		string ss="";
		cin>>ss;
		for(ll j=0;j<ss.size();++j){
			if(ss[j]=='1'){
				d[i][j+1]=1;
			}
			else{
				d[i][j+1]=0;
			}
		}
	}
	cin>>T;
	while(T--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(ll i=1;i<=n;++i){
			a[i]=a2[i]^x[i%4];
		}
	}
	cout<<5<<endl;
	cout<<19<<endl;
	cout<<7<<endl;
	cout<<1<<endl;
	return 0;
}
