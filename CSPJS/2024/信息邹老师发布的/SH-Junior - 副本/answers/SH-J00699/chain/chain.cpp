#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Rset(x) Set(x,0)
#define cll const long long
using namespace std;
bool RET;
cll N=200009;
vector<ll> wb[N],qry[109],id[109];
ll n,k,q,MXR; bool ans[N];
ll input(ll& mx){
	cin>>n>>k>>q;ll sum=0; MXR=mx=0;
	rep(i,1,n){
		ll l;cin>>l;sum+=l;
		rep(j,1,l){ll x;cin>>x;wb[i].push_back(x);mx=max(mx,x);}
	}
	rep(i,1,q){
		ll r,c;cin>>r>>c; MXR=max(MXR,r); mx=max(mx,c);
		qry[r].push_back(c),id[r].push_back(i);
	}
	return sum;
}
namespace R1{
	bool ok[N];
	void solveR1(ll mx){
		rep(i,1,mx)ok[i]=0;
		rep(i,1,n){
			ll l=wb[i].size();
			multiset<ll> ms;
			rep(x,0,l-1){
				if(x>=k)ms.erase(ms.find(wb[i][x-k]));
				if(x!=0&&(*ms.begin())==1)ok[wb[i][x]]=1;
				ms.insert(wb[i][x]);
			}
		}
		rep(i,0,q-1)ans[i]=ok[qry[1][i]];
	}
}
void clr(vector<ll>&t){t.clear(),t.shrink_to_fit();}
void clear(ll mx){
	rep(i,1,n)clr(wb[i]);
	rep(i,1,mx)clr(qry[i]),clr(id[i]);
}
bool ok[109][N];
namespace Solution{
	bool f[11][1009][2009],g[109][N];ll val[109][N],vp[N];
	vector<ll> ID[N];
	map<ll,ll> mp[N];
	vector<ll> R[N],C[N];
	void solveR1(ll mx,bool t){
		rep(i,1,n){
			ll l=wb[i].size();
			multiset<ll> ms;
			rep(x,0,l-1){
				if(x>=k)ms.erase(ms.find(wb[i][x-k]));
				if(x!=0&&(*ms.begin())==1){
					if(t)f[1][i][x]=1;else g[1][ID[i][x]]=1;
//					if(t)cerr<<"sf"<<endl;
					ok[1][wb[i][x]]=1;
				}
				ms.insert(wb[i][x]);
			}
		}
	}
	void solveBF(ll mx){
		rep(i,1,mx)clr(R[i]),clr(C[i]);
		rep(i,1,n)clr(ID[i]);
		rep(i,1,MXR)rep(j,1,mx)ok[i][j]=0;
		rep(i,1,n){
			ll l=wb[i].size();
			rep(j,0,l-1){
				R[wb[i][j]].push_back(i),C[wb[i][j]].push_back(j);
				rep(R,1,MXR)f[R][i][j]=0;
			}
		} ll cnt=0;
		rep(i,1,n){
			ll l=wb[i].size();
			rep(j,0,l-1){
				rep(R,1,MXR)f[R][i][j]=0;
				ID[i].push_back(++cnt);
			}
		}
		solveR1(mx,1);
		rep(o,2,MXR){
			rep(i,1,n){
				ll l=wb[i].size();
				rep(j,0,l-1)rep(x,max(0ll,j-k+1),j-1){
					ll lst=wb[i][x];
					for(ll a=0;a<R[lst].size();a++){
						ll r=R[lst][a],c=C[lst][a];
						if(r==i)continue;
						f[o][i][j]|=f[o-1][r][c];
					}
				}
			}
			rep(i,1,n){
				ll l=wb[i].size();
				rep(j,0,l-1)if(f[o][i][j])ok[o][wb[i][j]]=1;
			}
		}
		rep(R,1,MXR)for(ll i=0;i<qry[R].size();++i)ans[id[R][i]]=ok[R][qry[R][i]];
	}
	void solve(ll mx){
		rep(i,1,MXR)rep(j,1,mx)ok[i][j]=0; ll cnt=0;
		rep(i,1,n)clr(ID[i]);
		rep(i,1,n){
			ll l=wb[i].size();
			rep(j,0,l-1){
				rep(R,1,MXR)g[R][ID[i][j]]=0;
				ID[i].push_back(++cnt);
			}
		}
		solveR1(mx,0);
		rep(i,1,cnt)vp[i]=0;
		rep(i,1,n){
			mp[i].clear();
			ll l=wb[i].size(),sum=0;
			rep(j,0,l-1){
				vp[wb[i][j]]+=g[1][ID[i][j]];
				mp[i][wb[i][j]]+=g[1][ID[i][j]];
			}
		}
		rep(i,1,n){
			ll l=wb[i].size();rep(j,0,l-1)val[1][ID[i][j]]=vp[wb[i][j]]-mp[i][wb[i][j]];
//			rep(j,0,l-1)if(g[1][ID[i][j]])cerr<<"ff"<<endl;
		}
		rep(o,2,MXR){
			rep(i,1,cnt)vp[i]=0;
			rep(i,1,n){
				mp[i].clear();
				ll l=wb[i].size(),sum=0;
				rep(j,0,l-1){
					if(j>=k)sum-=val[o-1][ID[i][j-k]];
					if(sum)g[o][ID[i][j]]=1;
					sum+=val[o-1][ID[i][j]];
					vp[wb[i][j]]+=g[o][ID[i][j]];
					mp[i][wb[i][j]]+=g[o][ID[i][j]];
				}
			}
			rep(i,1,n){ll l=wb[i].size();rep(j,0,l-1)val[o][ID[i][j]]=vp[wb[i][j]]-mp[i][wb[i][j]];}
			rep(i,1,n){
				ll l=wb[i].size();
				rep(j,0,l-1)if(g[o][ID[i][j]])ok[o][wb[i][j]]=1;
			}
		}
		rep(R,1,MXR)for(ll i=0;i<qry[R].size();++i)ans[id[R][i]]=ok[R][qry[R][i]];
	}
}
void prt(){rep(i,1,q)cout<<ans[i]<<endl;}
bool QWE;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ll t;cin>>t;
	while(t--){
		ll mx=-1;
		ll sum=input(mx);
		if(qry[1].size()==q)R1::solveR1(mx);
		else if(sum<=2000&&MXR<=10&&n<=1000)Solution::solveBF(mx);
		else Solution::solve(mx);
		prt();
		clear(mx);
	}
	return 0;
}
