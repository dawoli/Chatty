#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5;
ll n,r[N+5],cnt[N+5],a[N+5],b[N+5];
void init(){
	cin>>n;
	ll Max=-1;
	for(ll i=1;i<=n;i++){
		cin>>r[i];
		cnt[r[i]]++;
		Max=max(Max,r[i]);
	}
	ll len=0;
	for(ll i=1;i<=Max;i++)
		if(cnt[i]>0)
			a[++len]=cnt[i];
	n=len;
	for(ll i=1;i<=n;i++)
		b[i]=a[i];
}
ll solve(){
	if(n==1)	return a[1]; 
	for(ll i=2;i<=n;i++){
		ll t=1;
		bool flag=true;
		while(a[i-t]<b[i]){
			b[i]-=a[i-t];
			a[i-t]=0;
			b[i-t]=0;
			t++;
			if(t==i){
				flag=false;
				break;
			}
		}
		if(flag==false)	continue;
		a[i-t]-=b[i];
		if(a[i-t]<0)	a[i-t]=0;
		b[i-t]=a[i-t];
		b[i]=0;
	}
	ll sum=0;
	for(ll i=1;i<=n;i++)
		sum+=a[i];
	return sum;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	init();
	cout<<solve()<<endl;
	return 0;
}
