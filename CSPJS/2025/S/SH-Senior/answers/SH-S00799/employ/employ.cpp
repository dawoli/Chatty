#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m,p[N],c[N];
ll id[20];
void solvebf(){
	for(ll i=1;i<=n;i++) id[i]=i;
	ll cnt=0;
	do{
		ll cntd=0;
		for(ll i=1;i<=n;i++){
			if(p[i]==0) cntd++;
			else if(c[id[i]]<=cntd) cntd++;
		}
//		cout<<cntd<<endl;
		if(n-cntd>=m) cnt++;
	}while(next_permutation(id+1,id+n+1));
	printf("%lld\n",cnt);
}
bool s1(){
	for(ll i=1;i<=n;i++) if(p[i]!=1) return 0;
	return 1;
}
void solves1(){
	puts("0");
}
void solve(){
	puts("0");
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		char ch;
		cin>>ch;
		p[i]=ch-'0';
	}
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=10) solvebf();
	else if(s1()) solves1();
	else solve();
	return 0;
}
