#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=200005;
ll L,n,q,szt,szs[N];
string s[N][2],t[2];
vector<ll> nxt[N][2];
void Getnxt(ll ii,ll jj){
	nxt[ii][jj].push_back(-1);
	ll i=1,j=0;
	ll sz=szs[ii];
	for(ll k=1;k<=sz;++k)nxt[ii][jj].push_back(0);
	while(i<sz){
		if(j<0||s[ii][jj][i]==s[ii][jj][j]){
			i++;
			j++;
			nxt[ii][jj][i]=j;
		}
		else{
			j=nxt[ii][jj][j];
		}
	}
}
ll g[N];
ll solBF(ll k,ll l,ll r){
	for(ll i=0;i<=szt;++i)g[i]=0;
	ll i=0,j=0;
	while(i<szt){
		if(j<0||s[k][0][j]==t[0][i]){
			i++;
			j++;
			if(j>=szs[k]){
				if(i-szs[k]<=l&&r<=i-1){
					g[i]=1;
				}
				j=nxt[k][0][j];
			}
		}
		else{
			j=nxt[k][0][j];
		}
	}
	i=0,j=0;
	ll ret=0;
	while(i<szt){
		if(j<0||s[k][1][j]==t[1][i]){
			i++;
			j++;
			if(j>=szs[k]){
				if(g[i]){
					ret++;
				}
				j=nxt[k][1][j];
			}
		}
		else{
			j=nxt[k][1][j];
		}
	}
	return ret;
}
void solveBF(){
	for(ll i=1;i<=n;++i){
		Getnxt(i,0);
		Getnxt(i,1);
	}
	ll l,r;
	for(ll i=1;i<=q;++i){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		szt=t[0].size();
		l=szt,r=-1;
		for(ll j=0;j<szt;++j){
			if(t[0][j]!=t[1][j]){
				l=min(l,j);
				r=j;
			}
		}
		ll ans=0;
		for(ll j=1;j<=n;++j){
			if(szs[j]>szt)continue;
			ans+=solBF(j,l,r);
		}
		cout<<ans<<"\n";
	}
}
ll d[N],topd=0;
ll solA(ll k,ll l,ll r){
	topd=0;
	ll i=0,j=0;
	while(i<szt){
		if(j<0||s[k][0][j]==t[0][i]){
			i++;
			j++;
			if(j>=szs[k]){
				if(i-szs[k]<=l&&r<=i-1){
					g[i]=1;
					topd++;
					d[topd]=i;
				}
				j=nxt[k][0][j];
			}
		}
		else{
			j=nxt[k][0][j];
		}
	}
	if(topd<=0)return 0;
	i=0,j=0;
	ll ret=0;
	while(i<szt){
		if(j<0||s[k][1][j]==t[1][i]){
			i++;
			j++;
			if(j>=szs[k]){
				if(g[i]){
					ret++;
				}
				j=nxt[k][1][j];
			}
		}
		else{
			j=nxt[k][1][j];
		}
	}
	while(topd>0){
		g[d[topd]]=0;
		topd--;
	}
	return ret;
}
void solveA(){
	for(ll i=1;i<=n;++i){
		Getnxt(i,0);
		Getnxt(i,1);
	}
	ll l,r;
	for(ll i=1;i<=q;++i){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		szt=t[0].size();
		l=szt,r=-1;
		for(ll j=0;j<szt;++j){
			if(t[0][j]!=t[1][j]){
				l=min(l,j);
				r=j;
			}
		}
		ll ans=0;
		for(ll j=1;j<=n;++j){
			if(szs[j]>szt||szs[j]<r-l+1)continue;
			ans+=solA(j,l,r);
		}
		cout<<ans<<"\n";
	}
}
void solveB(){
	solveA();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool ifA=1;
	for(ll i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		szs[i]=s[i][0].size();
		L+=szs[i]+szs[i];
	}
	if(L<=2000){
		solveBF();
	}
	else if(ifA){
		solveA();
	}
	else{
		solveB();
	}
	return 0;
}
