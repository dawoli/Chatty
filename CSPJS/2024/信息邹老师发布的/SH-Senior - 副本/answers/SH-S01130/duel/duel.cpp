#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll monster[100009];
ll num[100009];
ll remain[100009];
bool less2=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>monster[i];
		if(monster[i]>2) less2=0; 
	}
	if(less2){
		ll two=0;ll one=0;
		for(ll i=1;i<=n;i++){
			if(monster[i]==1) one++;
			else two++;
		}
		if(two<=one){
			cout<<one;
		}else{
			cout<<two;	
		}
		return 0;
	} 
	sort(monster+1,monster+1+n);
	bool uniq=1;
	for(ll i=2;i<=n;i++){
		if(monster[i]==monster[i-1]){
			uniq=0;
			break;
		}
	}
	if(uniq){
		cout<<n/2<<endl;
		return 0;
	}
	ll last=1;
	ll cnt=0;
	for(ll i=2;i<=n;i++){
		if(monster[i]>monster[last]){
			cnt++; remain[cnt]=num[cnt]=i-last;
			last=i;
		}
	}
	cnt++;
	remain[cnt]=num[cnt]=n+1-last;
	for(ll i=2;i<=cnt;i++){
		if(num[i]<remain[i-1]){
			remain[i]+=(remain[i-1]-num[i]);
		}
	}
	cout<<remain[cnt]<<endl;
	return 0;
} 
