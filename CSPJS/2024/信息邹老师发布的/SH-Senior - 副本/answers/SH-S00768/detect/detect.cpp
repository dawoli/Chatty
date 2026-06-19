#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
bool flag1=1;
ll T,n,m,L,V;
ll dp[N],d[N],v[N],a[N],x[N];
struct node{
	ll ar,de,idid;
}e[N];
void solve1(){
	ll cnt=0,maxm=0;
	for(int i=1;i<=m;i++) maxm=max(x[i],maxm);
	for(int i=1;i<=n;i++){
		if(v[i]>V&&d[i]<=maxm) cnt++;
	}
	cout<<cnt<<" "<<(cnt==0?m:m-1)<<endl;
}
bool cmp(node a,node b){
	return a.ar<b.ar||a.ar==b.ar&&a.de>b.de;
}
void solve(){
	ll prede=0,cnt=0;
	for(int i=1;i<=n;i++){
		e[i].idid=i;
		if(a[i]>0){
			e[i].de=L;
			if(v[i]>=V){
				e[i].ar=d[i];
				continue;
			}
			e[i].ar=min(L+1,d[i]+(int)(ceil((double)(1.0*V*V-v[i]*v[i])/(2*a[i]))));
			continue;
		}
		if(a[i]==0){
			if(v[i]>V){
				e[i].ar=d[i];
				e[i].de=L;
			}
			continue;
		}
			if(v[i]<=V){
				e[i].ar=0;
				e[i].de=0;
				continue;
			}	
			e[i].ar=d[i];
			e[i].de=min(L,d[i]+(int)(ceil((double)(1.0*v[i]*v[i]-V*V)/(2*abs(a[i]))))-1);
			//e[i].de=min(L,d[i]+(int)(ceil((double)(v[i]*v[i]*1.0)/(2*abs(a[i])))));
	}
	sort(e+1,e+n+1,cmp);
	sort(x+1,x+m+1);
	for(int i=1;i<=n;i++){
		//cout<<e[i].ar<<" "<<e[i].de<<" "<<e[i].idid<<" ";
		ll id=lower_bound(x+1,x+m+1,e[i].ar)-x;
		//cout<<id<<endl;
		if(x[id]==0) continue;
		if(x[id]<=e[i].de) cnt++;
	}
	dp[1]=1;
	prede=e[1].de;
	for(int i=2;i<=n;i++){
		if(e[i].ar==0&&e[i].de==0) continue;
		if(e[i].ar>L){
			dp[i]=dp[i-1];
			continue;
		}
		if(e[i].de<=e[i-1].de){
			dp[i]=dp[i-1];
			prede=e[i].de;
			continue;
		}
		else{
			if(e[i].ar<=prede){
				dp[i]=dp[i-1];
				continue;
			}
			dp[i]=dp[i-1]+1;
			prede=e[i].de;
		}
	}
	//for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	//cout<<endl;
	cout<<cnt<<" "<<m-dp[n]<<endl; 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0) flag1=0;
		}
		for(int i=1;i<=m;i++) cin>>x[i];
		if(flag1) solve1();
		else solve();
	} 
	return 0;
}
