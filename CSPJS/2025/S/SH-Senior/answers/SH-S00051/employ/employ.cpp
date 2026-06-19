#include<bits/stdc++.h>
#define N 505
#define MOD 998244353
typedef long long ll;
using namespace std;
struct Employ{
	ll x,id;
	bool operator<(const Employ&b)const{
		return id<b.id;
	}
}c[N];
ll n,m,ans;
string s;
ll AA(ll nN,ll M){
	ll ans=1;
	for(ll i=0;i<M;i++) ans=ans*(nN-i)%MOD;
	return ans;
}
bool cmpX(const Employ&a,const Employ&b){
	return a.x>b.x;
}
bool A(){
	for(ll i=1;i<=n;i++) if(s[i-1]!='1') return 0;
	return 1;
}
void Solve1_2(){
	do{
		ll tmp=0,t=0;
		for(ll i=1;i<=n;i++)
			if(t<c[i].x){
				if(s[i-1]=='1') tmp++;
				else t++;
			}
			else t++;
		if(tmp>=m) ans++;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans;
}
void SolveA(){
	;
}
void Solve12_14(){
	for(ll i=1;i<=n;i++) if(s[i-1]=='1'){
		sort(c+1,c+1+n,cmpX);
		ll tx=0;
		for(ll j=1;j<=n;j++)
			if(c[j].x>i-1) tx++;
			else break;
		ans=(ans+tx*AA(n,i-1)*AA(n-i,n-i)%MOD)%MOD;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>c[i].x,c[i].id=i;
	if(n<=10) Solve1_2();			//8pts
	else if(A()) SolveA();			//20pts Î´½â
	else if(m==1) Solve12_14();		//12pts ´í½â
	return 0;
}
