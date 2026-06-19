#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll m;
ll ans;
ll x[500009];
ll y[500009][10];
bool all1(){
	for(ll i=0;i<n;i++){
		if(x[i]!=0&&x[i]!=1)return 0;
	}
	return 1;
} 
void solve0(){
	for(ll i=0;i<n;i++)if(x[i]==0)ans++;
	for(ll i=0;i<n;i++){
		if(x[i]==1&&x[i+1]==1){
			x[i]=x[i+1]=0;
			ans++;
		}
	}
	cout<<ans<<endl;
}
void solve1(){
	for(ll i=0;i<n;i++)if(x[i]==1)ans++;
	cout<<ans<<endl;
}
void rte(ll i){
	ll o=x[i];
	ll cnt=128;
	for(ll j=7;j>=0;j--){
		if(o-cnt>=0){
			o-=cnt;
			y[i][j]=1;
		}
		cnt/=2;
	} 
}
bool xr(ll i,ll j){
	if(i==j)return 0;
	return 1;
}
void solve255(){
	for(ll i=0;i<n;i++){
		rte(i);
	}
	ll cnt[8];
	fill(cnt,cnt+8,0);
	for(ll i=0;i<n;i++){
		for(ll j=1+1;j<n;j++){
			for(ll k=0;k<8;k++)cnt[k]=y[i][k];
			for(ll k=i+1;k<=j;k++){
				for(ll o=0;o<8;o++)cnt[o]=xr(cnt[o],y[i][o]);
			}
			ll cnt2=1;
			ll cnt3=0;
			for(ll i=0;i<8;i++){
				if(cnt[i])cnt3+=cnt2;
				cnt2*=2;
			}
			if(cnt3==m)ans++;
		}
	}
	cout<<ans<<endl;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>x[i];
	if(m==0&&all1){
		solve0();
	}else if(m==1&&all1){
		solve1();
	}else if(m<=255){
		solve255();
	}
	return 0;
}
