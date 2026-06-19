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
ll cnt[]={6,2,5,5,4,5,6,3,7,6};
void solve7(ll t){rep(i,1,t/7)cout<<"8";cout<<endl;}
void solveBF(ll t){
	rep(i,1,100000){
		ll sum=0,x=i;
		do{sum+=cnt[x%10],x/=10;}while(x);
		if(sum==t){cout<<i<<endl;return;}
	}
	cout<<-1<<endl;
}
void solve(ll n){
	if(n%7==1)cout<<"10",n-=8;
	else if(n%7==2)cout<<"1",n-=2;
	else if(n%7==3)cout<<"200",n-=17;
	else if(n%7==4)cout<<"20",n-=11;
	else if(n%7==5)cout<<"2",n-=5;
	else cout<<"6",n-=6;
	solve7(n);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ll t;cin>>t;while(t--){
		ll n;cin>>n;
		if(n%7==0)solve7(n);
		else if(n<=35)solveBF(n);
		else solve(n);
	}
	return 0;
}

