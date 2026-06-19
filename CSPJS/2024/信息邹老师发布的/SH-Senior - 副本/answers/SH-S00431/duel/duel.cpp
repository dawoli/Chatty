#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
ll n,a[N],box[N];
priority_queue<ll,vector<ll>,greater<ll> > qAlive,qAttack;
void input(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
}
bool check2(){
	for(int i=1;i<=n;++i)
		if(a[i]>2) return false;
	return true;
}
void solve2(){
	ll cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i)
		if(a[i]==1) ++cnt1;
		else ++cnt2;
//	cout<<cnt1<<" "<<cnt2<<"\n";
	if(cnt1>=cnt2)
		cout<<cnt2+cnt2-cnt1;
	else cout<<cnt2;
}
void solve(){
	for(int i=1;i<=n;++i)
		qAttack.push(a[i]),qAlive.push(a[i]);
	while(!qAttack.empty()){
		//cout<<qAttack.size()<<" "<<qAlive.size()<<"\n";
		ll att=qAttack.top();
		ll die=qAlive.top();
		while(att<=die){
			qAttack.pop();
			if(qAttack.empty()) break;
			att=qAttack.top();
		}//cout<<att<<" "<<die<<"\n";
		if(qAttack.empty()) break;
		qAlive.pop();
		qAttack.pop();
	}cout<<qAlive.size();
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input();
	if(check2()) solve2();
	else solve();
	return 0;
} 
