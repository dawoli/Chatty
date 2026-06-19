#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,l,a[1000010],d[1000010],ans,v[1000010],maxx,p[1000010];
double vv;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		maxx=0;
		cin>>n>>m>>l>>vv;
		for(int i=1;i<=n;i++){cin>>d[i]>>v[i]>>a[i];}
		if(a[1]!=0){
			for(int i=1;i<=m;i++){cin>>p[i];maxx=max(maxx,p[i]);}
			for(int i=1;i<=n;i++)if(d[i]<=maxx)if(sqrt((v[i]*v[i]+2*a[i]*(maxx-d[i]))*1.00)>vv*1.00)ans++;
			if(ans>0)cout<<ans<<" "<<m-1<<endl;
			else cout<<"0 "<<m<<endl;
		}
		else{
			for(int i=1;i<=m;i++){cin>>p[i];maxx=max(maxx,p[i]);}
			for(int i=1;i<=n;i++)if(d[i]<=maxx&&v[i]>vv)ans++;
			if(ans>0)cout<<ans<<" "<<m-1<<endl;
			else cout<<"0 "<<m<<endl;
		}
	}
	return 0;
}
