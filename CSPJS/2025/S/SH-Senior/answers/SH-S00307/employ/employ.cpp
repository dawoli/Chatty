#include<bits/stdc++.h>
#define moo 998244353
using namespace std;
typedef unsigned long long ll;
ll n,m,ans,pai[514],c[514];
char tp;
bitset<514> ss;

void dfs(ll pos,ll hh,ll cc,ll stt){
	if(cc<c[pos]&&ss[hh+cc])++hh;
	else ++cc;
//	cout<<pos<<hh<<cc<<" "<<stt<<"\n";
	if(hh==m){
		ans=(ans+pai[n-hh-cc])%moo;
		return;
	}
	for(ll i=0;i<n;++i){
		if(((1<<i)&stt))continue;
		dfs(i,hh+1,cc,(stt|(1<<i)));
	}
	for(ll i=0;i<n;++i){
		if(((1<<i)&stt))continue;
		dfs(i,hh,cc+1,(stt|(1<<i)));
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	pai[0]=pai[1]=1;
	for(int i=2;i<=500;++i){
		pai[i]=pai[i-1]*i%moo;
//		cout<<"pai"<<pai[i]<<"\n";
	}
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>tp;
		if(tp=='1')ss[i]=1;
	}
	for(int i=0;i<n;++i)cin>>c[i];
	for(ll i=0;i<n;++i){
			dfs(i,0,0,(1<<i));
	}
	cout<<ans;
	return 0;
}
