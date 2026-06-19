#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll INF=1e15;
const ull BASE=240441620163;
const ll MOD=998244353;
void file(){
	 freopen("employ.in","r",stdin);
	 freopen("employ.out","w",stdout);
}
//本人最后一个赛季，祭~
//感谢八年来OI带来的欢乐，以及不一样的人生经历~
const ll N=509;
ll n,m,mp[N],id[N],c[N];
void input(){
	cin>>n>>m;
	rep(i,1,n){
		char s; cin>>s;
		if(s=='0')mp[i]=0;
		else mp[i]=1;
	}
	rep(i,1,n)cin>>c[i];
}
bool all1(){
	rep(i,1,n)if(mp[i]==0)return 0;
	return 1;
}
bool all_not_0(){
	rep(i,1,n)if(c[i]==0)return 0;
	return 1;
}
void solve_mn(){
	if(all1()&&all_not_0()){
		ll ans=1;
		rep(i,1,n)(ans*=i)%=MOD;
		cout<<ans<<endl;
		return;
	}
	cout<<0<<endl;
}
void solveBF(){
	rep(i,1,n)id[i]=i;
	ll ans=0;
	do{
		ll res=0,cnt=0;
		rep(i,1,n){
			if(cnt>=c[id[i]])cnt++;
			else if(mp[i])res++;
			else cnt++;
		}
		if(res>=m){
			(ans+=1)%=MOD;
//			rep(i,1,n)cout<<id[i]<<" ";
//			cout<<endl;
		}
	}while(next_permutation(id+1,id+1+n));
	cout<<ans<<endl;
}
int main(){
	file();
	input();
	if(m==n)
		solve_mn();
	else 
		solveBF();
	return 0;
}


