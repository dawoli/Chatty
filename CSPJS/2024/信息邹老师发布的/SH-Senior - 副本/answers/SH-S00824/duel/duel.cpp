#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll R=1e5+9;
ll n,m,tmp[R],cnt[R],smaller[R];
map<ll,ll> M;
void FIO(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
}
void genData(){
	n=1e5;
	srand(time(NULL));
	for(ll i=1;i<=n;i++){
		tmp[i]=rand()*rand()%10000;
	}
}
ll solveBF(){
	ll ans=0;
	for(ll i=2;i<=m;i++){ 
		ll change=min(cnt[i],smaller[i]);
		ans+=change;
		for(ll j=i;j<=m;j++){
			smaller[j]-=change;
		}
	}
	return n-ans; 
}
ll solve(){
	ll ans=0;
	for(ll i=2;i<=m;i++){
		ll change=min(cnt[i],smaller[i]-ans);
		ans+=change;
	}
	return n-ans; 
}
void operate(){
	sort(tmp+1,tmp+1+n);
	for(ll i=1;i<=n;i++){
		if(M[tmp[i]]==0){
			m++;M[tmp[i]]=m;
		}
		cnt[M[tmp[i]]]++;
	}
	for(ll i=1;i<m;i++){
		smaller[i+1]=smaller[i]+cnt[i];
	}
}
void Test(){
	for(ll T=1;T<=100;T++){	
		genData();
		operate();
		ll S1,S2;
		S1=solve();
		S2=solveBF();
		if(S1!=S2){
			cout<<S1<<" "<<S2;return;
		}
	}
	cout<<"OK";
}
int main(){
	ios::sync_with_stdio(false);
	FIO();
//	Test();
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>tmp[i];
	}
	operate();
	if(tmp[n]==2){
		cout<<n-min(cnt[1],cnt[2])<<endl;
	} 
//	else if(n<=30){
//		cout<<solveBF();
//	}
	else cout<<solve()<<endl; 
	return 0;
} 
