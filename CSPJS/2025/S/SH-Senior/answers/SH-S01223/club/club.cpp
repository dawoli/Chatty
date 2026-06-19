#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++) 
#define mk(x,y) make_pair(x,y)
ll r(){
	ll x=0;char c='a';
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
} 
struct emp{
	ll u,v,w;
}q[maxn];
ll ans;
int num[5];
priority_queue<ll> ok1;
priority_queue<ll> ok2;
priority_queue<ll> ok3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T=r();
	while(T--){
		int ct=0;
		ans=0;
		int n=r();
		rep(i,1,3)num[i]=0;
		rep(i,1,n){
			q[i].u=r();
			q[i].v=r();
			q[i].w=r();
		}
		while(!ok1.empty()){
				ok1.pop();
			}	
		while(!ok2.empty()){
				ok2.pop();
			}
		while(!ok3.empty()){
				ok3.pop();
			}
		rep(i,1,n){
			if(max(q[i].u,max(q[i].v,q[i].w))==q[i].u){
				num[1]++;ans+=q[i].u;
//				cout<<1<<max(q[i].u,max(q[i].v,q[i].w))<<i<<endl;
				if(q[i].v>q[i].w){
					ok1.push(q[i].v-q[i].u);
				}
				else{
					ok1.push(q[i].w-q[i].u);
				}
			}
			else if(max(q[i].u,max(q[i].v,q[i].w))==q[i].v){
				num[2]++;ans+=q[i].v;
				if(q[i].u>q[i].w){
					ok2.push(q[i].u-q[i].v);
				}
				else{
					ok2.push(q[i].w-q[i].v);
				}
			}
			else if(max(q[i].u,max(q[i].v,q[i].w))==q[i].w){
				num[3]++;ans+=q[i].w;
				if(q[i].v>q[i].u){
					ok3.push(q[i].v-q[i].w);
				}
				else{
					ok3.push(q[i].u-q[i].w);
				}
			}
		}
		if(num[1]>n/2){
			rep(i,1,num[1]-n/2){
				ans+=ok1.top();ok1.pop();
			}
		}
		if(num[2]>n/2){
			rep(i,1,num[2]-n/2){
				ans+=ok2.top();ok2.pop();
			}
		} 
		if(num[3]>n/2){
			rep(i,1,num[3]-n/2){
				ans+=ok3.top();ok3.pop();
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
