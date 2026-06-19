#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,cntu,cntv,cntw,u,v,w;
vector<int> a,b,c;
void cul(ll u,ll v,ll w){
	if(u>=v && u>=w){
		cntu++,ans+=u;
		a.push_back(min(u-v,u-w));
	}
	else if(v>=u && v>=w){
		cntv++,ans+=v;
		b.push_back(min(v-u,v-w));
	}
	else{
		cntw++,ans+=w;
		c.push_back(min(w-u,w-v));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cntu=cntv=cntw=ans=0;
		a.clear();
		b.clear();
		c.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>u>>v>>w;
			cul(u,v,w);
		}
		if(cntu>n/2){
			sort(a.begin(),a.end());
			for(int i=0;cntu>n/2;cntu--,i++)
				ans-=a[i];
		}
		if(cntv>n/2){
			sort(b.begin(),b.end());
			for(int i=0;cntv>n/2;cntv--,i++)
				ans-=b[i];
		}
		if(cntw>n/2){
			sort(c.begin(),c.end());
			for(int i=0;cntw>n/2;cntw--,i++)
				ans-=c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
