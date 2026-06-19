#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
typedef long long ll;
ll v[100005][3],t,n;
ll f[205][105][105];
void solve_BF(){
	memset(f,-0x3f,sizeof(f));
	f[0][0][0]=0;
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<3;j++)
			for(ll a=0;a<=n/2;a++)
				for(ll b=0;b<=n/2;b++){
					ll c=i-1-a-b;
					ll x[3]={a,b,c};
					++x[j];
					if(x[2]>n/2)continue;
					f[i][x[0]][x[1]]=max(f[i][x[0]][x[1]],f[i-1][a][b]+v[i][j]);
				}
	ll res=0;
	for(ll a=0;a<=n/2;a++)
		for(ll b=0;b<=n/2;b++)
			if(n-a-b<=n/2)res=max(res,f[n][a][b]);
	printf("%lld\n",res);
}
ll x[100005];
void solve_A(){
	for(ll i=1;i<=n;i++)x[i]=v[i][0];
	sort(x+1,x+1+n);
	ll res=0;
	for(ll i=n;n-i+1<=n/2;i--)res+=x[i];
	printf("%lld\n",res);
}
ll heap[100005],top;
void push(ll x){
	heap[++top]=x;
	ll u=top;
	while(u>1){
		ll fa=u>>1;
		if(heap[fa]<heap[u])return;
		swap(heap[fa],heap[u]);
		u=fa;
	} 
}
void pop(){
	if(top==0)return;
	heap[1]=heap[top--];
	ll u=1;
	while((u<<1)<=top){
		ll v=u<<1;
		if(v<top&&heap[v+1]<heap[v])++v;
		if(heap[u]<heap[v])return;
		swap(heap[u],heap[v]);
		u=v;
	}
}
vector<ll>g[3];
void solve(){
	for(ll k=0;k<3;k++)g[k].clear();
	for(ll i=1;i<=n;i++){
		ll mx=max(v[i][0],max(v[i][1],v[i][2]));
		for(ll k=0;k<3;k++)
			if(v[i][k]==mx){g[k].push_back(i);break;}
	}
	ll k=0;
	for(ll j=1;j<3;j++)if(g[k].size()<g[j].size())k=j;
	ll res=0;
	for(ll j=0;j<3;j++)
		for(ll i=0;i<g[j].size();i++)
			res+=v[g[j][i]][j];
//	for(ll j=0;j<3;j++)printf("%lld ",g[j].size());
//	puts("");
//	printf("%lld\n",k);
	if(g[k].size()<=n/2){printf("%lld\n",res);return;}
	ll a,b;
	if(k==0)a=1,b=2;
	if(k==1)a=0,b=2;
	if(k==2)a=0,b=1;
	top=0;
	for(ll i=0;i<g[k].size();i++){
		ll id=g[k][i];
		push(min(v[id][k]-v[id][a],v[id][k]-v[id][b]));
	}
	for(ll i=1;i<=g[k].size()-n/2;i++)res-=heap[1],pop();
	printf("%lld\n",res);
}
int main(){
	file();
	scanf("%lld",&t);
	while(t--){
		bool spA=1,spB=1;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<3;j++)
				scanf("%lld",&v[i][j]);
		for(ll i=1;i<=n&&spA;i++)
			if(v[i][1]!=0||v[i][2]!=0)spA=0;
		if(spA)solve_A();
		else if(n<=200)solve_BF();
		else solve(); 
	//	solve();
	}
	return 0;
}
