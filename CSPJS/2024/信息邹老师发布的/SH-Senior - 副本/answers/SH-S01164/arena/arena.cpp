#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,q,k=0,mi[22],d[20][N],a[N],c[N],T,w[20][N],tmp[N];
map<ll,ll> mp;
set<ll> s;
bool allC=1;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
ll read2(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') return c^48;
}
ll dfs(ll bg,ll k){//[bg,bg+(1<<k)-1]最终决胜的人
//	cout<<k<<"\n";
	if(k==0) return bg;
	ll x=dfs(bg,k-1),y=dfs(bg+(1<<(k-1)),k-1);
	if(d[k][bg/(1<<k)+1]) return a[y]>=k+1?y:x;
	return a[x]>=k+1?x:y;
}
void calc(ll id){
	for(ll i=1;i<=c[id];++i) w[0][i]=i;//w[i][j]第i轮j~j+2^i-1
	for(ll i=1;i<=mp[c[id]];++i)//第i轮
		for(ll j=1;j<=c[id];j+=(1<<i)){
			ll x=w[i-1][j],y=w[i-1][j+(1<<(i-1))];
			if(d[i][j/(1<<i)+1]) w[i][j]=(a[y]>=i?y:x);
			else w[i][j]=(a[x]>=i?x:y);
		}
//				for(ll i=1;i<=mp[c[id]];++i,cout<<"\n")//第i轮
//					for(ll j=1;j<=c[id];j+=(1<<i))
//						cout<<w[i][j]<<" ";
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),q=read();
	mi[k]=1;
	mp[1]=0;
	while((1<<k)<n) ++k,mi[k]=mi[k-1]*2,mp[mi[k]]=k;
	for(ll i=1;i<=n;++i) a[i]=read();
	for(ll i=1;i<=q;++i) c[i]=read(),allC&=(mp[c[i]]||c[i]==1);
	for(ll i=1;i<=k;++i)
		for(ll j=1;j<=mi[k-i];++j)
			d[i][j]=read2();//d[R][G]:第R场的第G场比赛
	T=read();
	for(ll i=1;i<=T;++i){
		ll x[4],ans=0;
		x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
		for(ll i=1;i<=n;++i) a[i]^=x[i%4];
		if(n<=8){//(1<<k)-n
			for(ll id=1;id<=q;++id){
				s.clear();
				ll sum=0;
				ll peo=1;
				while(peo<c[id]) peo*=2;
				if(peo==c[id]){
					for(ll i=1;i<=peo;++i) w[0][i]=i;//w[i][j]第i轮j~j+2^i-1
					for(ll i=1;i<=mp[peo];++i)//第i轮
						for(ll j=1;j<=peo;j+=(1<<i)){
							ll x=w[i-1][j],y=w[i-1][j+(1<<(i-1))];
							if(d[i][j/(1<<i)+1]) w[i][j]=(a[y]>=i?y:x);
							else w[i][j]=(a[x]>=i?x:y);
						}
						sum+=w[mp[peo]][1];
				}else{
					for(ll i=1;i<=n;++i) tmp[i]=a[i];
					for(ll i=0;i<(1<<(peo-c[id]));++i){
						for(ll j=c[id]+1;j<=peo;++j)
							a[j]=((i&(1<<(j-c[id]-1)))?100:0);
//						if(c[id]==3)
//							cout<<peo<<"\n";
						for(ll i=1;i<=peo;++i) w[0][i]=i;//w[i][j]第i轮j~j+2^i-1
						for(ll i=1;i<=mp[peo];++i)//第i轮
							for(ll j=1;j<=peo;j+=(1<<i)){
								ll x=w[i-1][j],y=w[i-1][j+(1<<(i-1))];
								if(d[i][j/(1<<i)+1]) w[i][j]=(a[y]>=i?y:x);
								else w[i][j]=(a[x]>=i?x:y);
							}
							if(s.find(w[mp[peo]][1])==s.end()){
								sum+=w[mp[peo]][1];
//								if(c[id]==3) cout<<w[mp[peo]][1]<<",";
							}
							s.insert(w[mp[peo]][1]);
					}
					
					for(ll i=1;i<=n;++i) a[i]=tmp[i];
				}
//				cout<<id<<":"<<sum<<"\n";
				ans^=(id*sum);
			}
		}else if(allC){
			for(ll id=1;id<=q;++id){
//				ans^=(i*dfs(1,mp[c[i]]));
				calc(id);
				ans^=(id*w[mp[c[id]]][1]);
			}
		}
		cout<<ans<<"\n";
		for(ll i=1;i<=n;++i) a[i]^=x[i%4];
	}
	return 0;
}
