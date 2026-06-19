#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
struct awa{
	long long da[10],d,maxid,mxaid;
}a[100009];
long long n,m,ans,u[10];
long long cmp(awa x,awa y){
	return x.d>y.d;
}
void init(){
	u[0]=u[1]=u[2]=u[3]=u[4]=0;
	ans=0;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].da[1]>>a[i].da[2]>>a[i].da[3];
	for(int i=1;i<=n;i++){
		long long k=min(a[i].da[1],min(a[i].da[2],a[i].da[3]));
		a[i].da[1]-=k,a[i].da[2]-=k,a[i].da[3]-=k,ans+=k;
		if(a[i].da[1]==0&&a[i].da[2]>=a[i].da[3]) a[i].maxid=2,a[i].mxaid=3,a[i].d=a[i].da[2]-a[i].da[3];
		if(a[i].da[1]==0&&a[i].da[3]>=a[i].da[2]) a[i].maxid=3,a[i].mxaid=2,a[i].d=a[i].da[3]-a[i].da[2];
		if(a[i].da[2]==0&&a[i].da[3]>=a[i].da[1]) a[i].maxid=3,a[i].mxaid=1,a[i].d=a[i].da[3]-a[i].da[1];
		if(a[i].da[2]==0&&a[i].da[1]>=a[i].da[3]) a[i].maxid=1,a[i].mxaid=3,a[i].d=a[i].da[1]-a[i].da[3];
		if(a[i].da[3]==0&&a[i].da[1]>=a[i].da[2]) a[i].maxid=1,a[i].mxaid=2,a[i].d=a[i].da[1]-a[i].da[2];
		if(a[i].da[3]==0&&a[i].da[2]>=a[i].da[1]) a[i].maxid=2,a[i].mxaid=1,a[i].d=a[i].da[2]-a[i].da[1];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		//cout<<a[i].da[1]<<' '<<a[i].da[2]<<' '<<a[i].da[3]<<' '<<a[i].d<<'\n';
		if(u[a[i].maxid]<n/2) u[a[i].maxid]++,ans+=a[i].da[a[i].maxid];
		else u[a[i].mxaid]++,ans+=a[i].da[a[i].mxaid]; 
	}
	cout<<ans<<'\n';
	init();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long T=1;cin>>T;
	while(T--) solve(); 
}
//subscribe tasho11y(uid=1385732) in bilibili(in luogu)!!!
//at 3:40