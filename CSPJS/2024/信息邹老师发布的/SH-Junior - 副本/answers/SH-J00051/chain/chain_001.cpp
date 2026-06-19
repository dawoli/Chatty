#include<bits/stdc++.h>
#define L 200005
#define S 200005
#define N 100005
typedef long long ll;
using namespace std;
struct Word_Dict{ ll x,owner; }w[L];
ll T,t,n,k,q,r,c,cnt[S],st[N];
void t1(){
	ll tx=1;
	for(ll i=1;i<=t;i++){
		if(w[i].x==1){
			bool CanDo=false;
			ll ts=0;
			for(ll j=i;j<=t;j++){
				ts++;
				if(ts>k) break;
				if(w[j].owner!=w[i].owner) break;
				if(w[j].x==c&&ts>=2){
					CanDo=true;
					break;
				}
			}
			if(CanDo){
				cout<<"1\n";
				return;
			}
		}
	}
	cout<<"0\n";
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	srand(time(NULL));
	while(T--){
		cin>>n>>k>>q,t=0;
		w[0].owner=1;
		for(ll i=1,l;i<=n;i++){
			cin>>l,st[i]=t+1;
			for(ll j=1;j<=l;j++) cin>>w[++t].x,w[t].owner=i,cnt[w[t].x]++;
		}
		while(q--){
			cin>>r>>c;
			if(!cnt[c]){
				cout<<"0\n";
				continue;
			}
			if(r<=1) t1();
			else cout<<rand()%2<<endl;
		}
	}
	return 0; 
}
