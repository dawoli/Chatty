#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF=1e15;
void file(){
	 freopen("arena.in","r",stdin);
	 freopen("arena.out","w",stdout);
}
const ll N=200009;
ll n,m,ap[N],T,c[N],k,ra[N];
ll d[N][40],winner[N][40];
ll ok[N],attack[N];
void init(){
	rep(i,1,n)ra[i]=ok[i]=attack[i]=0;
}
ll get2K(ll x){
	rep(i,0,60){
		ll a=i;
		if((1LL<<a)>=x)return (1LL<<a);
	}
}
void input(){
	cin>>n>>m;
	rep(i,1,n)cin>>ap[i];
	rep(i,1,m)cin>>c[i];
	k=get2K(n);
	ll r=0;
	while(k){
		k/=2; r++;
		rep(i,1,k){
			char s;
			cin>>s;
			if(s=='0')d[r][i]=0;
			else d[r][i]=1;
		}
	}
	cin>>T;
}
ll getKK(ll x){
	rep(i,0,60){
		ll a=i;
		if((1LL<<a)>=x)return a;
	}
}
set<ll> s;
void dfs(ll now,ll ed,ll mx){
	if(now==ed+1){
		rep(i,1,ed)winner[i][0]=i;
		ll round=0;
//		cout<<"ed "<<ed<<endl;
//		rep(i,1,ed)cout<<attack[i]<<" ";
//		cout<<endl;
		while(ed){
			ed/=2; round++;
			rep(i,1,ed){
				ll pa=attack[winner[i*2-1][round-1]];
				ll pb=attack[winner[i*2][round-1]];
				if(d[round][i]==0){
					if(pa>=round)winner[i][round]=winner[i*2-1][round-1];
					else winner[i][round]=winner[i*2][round-1];
				}else{
					if(pb>=round)winner[i][round]=winner[i*2][round-1];
					else winner[i][round]=winner[i*2-1][round-1];
				}
			}
			if(ed==1){
				s.insert(winner[1][round]);
				return;
			}
		}
		return;
	}
	rep(i,0,mx){
		attack[now]=i;
		dfs(now+1,ed,mx);
	}
}
void solveBF(){
	ll ans=0;
	rep(i,1,m){
		if(c[i]==1){
			ans^=(i*1);
			continue;
		}
		ll mx=getKK(c[i]);
		ll st=c[i]+1,ed=get2K(c[i]);
		rep(j,1,c[i])attack[j]=ra[j];
		ll res=0;
		s.clear();
		dfs(st,ed,mx);
		while(!s.empty())res+=(*s.begin()),s.erase(s.begin());
//		cout<<res<<" ";
//		cout<<endl;
		ans^=(i*res);
	}
	cout<<ans<<endl;
}
void get_the_input(){
	ll p[10];
	cin>>p[0]>>p[1]>>p[2]>>p[3];
	rep(i,1,n)ra[i]=ap[i]^p[i%4];
}
int main(){
	file();
	input();
	rep(i,1,T){
		init();
		get_the_input();
//		rep(i,1,n)cout<<ra[i]<<" ";
//		cout<<endl;
		solveBF();
	}
	return 0;
}

