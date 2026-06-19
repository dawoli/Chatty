#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5;
ll t,n,a[N+5];
bool b[N+5];
void nxt(){
	ll pos=n;
	while(b[pos]==1){
		b[pos]=0;
		pos--;
	}
	b[pos]=1;
//	for(ll i=1;i<=n;i++)
//		cout<<b[i]<<" ";
//	cout<<endl;
}
ll pow2(ll x){
	ll ans=1;
	for(ll i=1;i<=x;i++)
		ans*=2;
	return ans;
}
ll pre1[N+5],pre0[N+5];
void pre(){
	for(ll i=2;i<=n;i++){
		if(b[i-1]==1)	pre1[i]=i-1;
		else	pre1[i]=pre1[i-1];
		if(b[i-1]==0)	pre0[i]=i-1;
		else	pre0[i]=pre0[i-1];	
	}
//	for(ll i=1;i<=n;i++)
//		cout<<"    "<<pre0[i]<<" "<<pre1[i]<<endl;
}
ll solveBF(){
	ll c=pow2(n);
	ll Max=-1;
	for(ll j=1;j<=c;j++){
		ll cnt=0;
		pre();
		for(ll i=1;i<=n;i++){
//			cout<<"i="<<i<<endl;
			if(b[i]==0){
				ll pos=pre0[i];
//				cout<<"pos "<<pos<<endl;
				if(a[pos]==a[i])	cnt+=a[i];
			}
			if(b[i]==1){
				ll pos=pre1[i];
//				cout<<"pos "<<pos<<endl;
//				cout<<"a[3]="<<a[3]<<",a[i]="<<a[i]<<",i="<<i<<endl;
//				cout<<"a[pos]="<<a[pos]<<",a[i]="<<a[i]<<endl;
				if(a[pos]==a[i]){
					cnt+=a[i];	
				}
			}
		}
//		cout<<cnt<<endl;
		Max=max(Max,cnt);
		nxt();
	}
	return Max;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++){
		cin>>n;
		for(ll j=1;j<=n;j++)
			cin>>a[j];
		cout<<solveBF()<<endl;
	}
	return 0;
} 
