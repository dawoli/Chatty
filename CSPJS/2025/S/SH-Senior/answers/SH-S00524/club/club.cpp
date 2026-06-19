/*
CSPS 2025 RP++
Code With Love by Hughpig(646208)
QwQ
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)
#define pb push_back

ll n,ans;
struct node{
	ll a,b,c;
	ll getmax(){
		return max(a,max(b,c));
	}
	ll getmid(){
		if(a==getmax())return max(b,c);
		else if(b==getmax())return max(a,c);
		else return max(a,b);
	}
	friend bool operator<(node x,node y){
		return x.getmax()-x.getmid()>y.getmax()-y.getmid();
	}
};

vector<node> v1,v2,v3;

void solve(){
	cin>>n;ans=0;v1.clear();v2.clear();v3.clear();
	up(1,n,i){
		ll a,b,c;cin>>a>>b>>c;node _=(node){a,b,c};
		ll qwq=max(a,max(b,c));ans+=qwq;
		if(qwq==a)v1.pb(_);
		else if(qwq==b)v2.pb(_);
		else v3.pb(_);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v3.begin(),v3.end());
	//cout<<v1.size()<<' '<<v2.size()<<' '<<v3.size()<<' ';
	if((int)v1.size()>n/2){
		for(int i=n/2;i<(int)v1.size();++i){
			ans-=v1[i].a;
			ans+=max(v1[i].b,v1[i].c);
		}
	}
	if((int)v2.size()>n/2){
		for(int i=n/2;i<(int)v2.size();++i){
			ans-=v2[i].b;
			ans+=max(v2[i].a,v2[i].c);
		}
	}
	if((int)v3.size()>n/2){
		for(int i=n/2;i<(int)v3.size();++i){
			ans-=v3[i].c;
			ans+=max(v3[i].a,v3[i].b);
		}
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	cin>>tc;
	while(tc--){
		solve();
	}
}
//14:46 过全部大样例。
//RP++
