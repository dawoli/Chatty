#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int mod=1e9+7;
int n,p,af[N],delta[N<<1],bef[N];
vector<int> G[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int posa,posb;
		for(int j=0;j<a.size();j++){
			if(a[i]=='b') posa=j;
			if(b[i]=='b') posb=j;
		} 
		af[i]=min(posa,posb),bef[i]=a.size()-max(posa,posb),delta[i]=posa-posb+n;
		G[delta[i]].push_back(i);
	}
	for(int i=1;i<=p;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		int posa,posb;
		for(int j=0;j<a.size();j++){
			if(a[i]=='b') posa=j;
			if(b[i]=='b') posb=j;
		}
		for(auto v:G[posa-posb+n]){
			if(af[v]<=min(posa,posb)&&bef[i]<=a.size()-max(posa,posb)) ans++;
		}
		cout<<ans<<endl;
	}
}

