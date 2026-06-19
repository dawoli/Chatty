#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][4],id[100005][4],ID,d[100005][4],p[100005],ans;
struct node{
	ll u,v;
	bool operator<(const node &x)const{
		return v>x.v;
	}
};
priority_queue<node> q[4];
bool cmp(ll x,ll y){
	return a[ID][x]>a[ID][y];
}
bool add(ll x,ll ip){
	ll s=id[x][ip];
	//cout<<x<<" "<<ip<<" "<<s<<" "<<q[s].size()<<endl;
	if(q[s].size()<n/2){
		q[s].push((node){x,d[x][ip]});
		return true;
	}
	if(q[s].top().v<d[x][ip]){
		ll u=q[s].top().u;
		ll su=id[u][++p[u]];
		q[su].push((node){u,d[u][p[u]]});
		q[s].pop();
		q[s].push((node){x,d[x][ip]});
		return true;
	}
	return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				id[i][j]=j;
			}
			ID=i;
			sort(id[i]+1,id[i]+4,cmp);
			for(ll j=1;j<=2;j++){
				d[i][j]=a[i][id[i][j]]-a[i][id[i][j+1]];
			}
		}
		for(ll i=1;i<=n;i++){
			if(add(i,1)){
				p[i]=1;
				continue;
			}
			add(i,2);
			p[i]=2;
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			//cout<<id[i][p[i]]<<" "<<a[i][id[i][p[i]]]<<endl;
			ans+=a[i][id[i][p[i]]];
		}
		cout<<ans<<endl;
		for(ll i=1;i<=3;i++){
			while(!q[i].empty()){
				q[i].pop();
			}
		}
	}
	return 0;
}

