#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T;
ll n,k,q;
vector<ll> s[N];
ll in[N];
struct Edge{
	ll to,nxt,tag;
}e[N*4]; // ?
ll hd[N],nE;
void link(ll u,ll v,ll tag){
	e[++nE]=(Edge){v,hd[u],tag};
	hd[u]=nE; 
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin>>T;
	while(T--){
		//init:
		nE=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
			hd[i]=0;
		for(int i=1;i<=n;i++){
			ll l; cin>>l;
			s[i].clear();
			for(int j=0;j<l;j++){
				ll x; cin>>x;
				s[i].push_back(x);
			}
		}
		for(int i=1;i<=n;i++){
			ll l=s[i].size();
			for(int j=0;j<l;j++)
				for(int p=j+1;p<=j+k-1&&p<l;p++)
					link(s[i][j],s[i][p],i);
		}
		for(int i=1;i<=q;i++){
			ll r,c;
			cin>>r>>c;
			//bfs
			queue<pair<ll,ll> > q;
			q.push(make_pair(1,-1));
			for(int i=1;i<=r;i++){
				for(int j=1;j<N;j++)
					in[j]=-2;
				while(!q.empty()){
					pair<ll,ll> u=q.front(); q.pop(); 
					for(int j=hd[u.first];j;j=e[j].nxt){
						if(u.second==e[j].tag) continue;
						if(in[e[j].to]!=e[j].tag&&in[e[j].to]!=-2)
							in[e[j].to]=-1;
						else in[e[j].to]=e[j].tag;
					}
				}
				q=queue<pair<ll,ll> >();
				for(int j=1;j<N;j++)
					if(in[j]!=-2)
						q.push(make_pair(j,in[j]));
			}
			bool flag=0;
			while(!q.empty()){
				ll m=q.front().first; q.pop();
				if(m==c){
					flag=1;
					break;
				}
			}
			cout<<flag<<endl;
		}
	}
	return 0;
}
