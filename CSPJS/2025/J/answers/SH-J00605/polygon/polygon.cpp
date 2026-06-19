#include<bits/stdc++.h>
using namespace std;
long long a[5009],n;
long long digui(long long mx,long long start,long long sm){
	long long ans=0;
	if(sm>2*a[mx]) ans++;
	for(long long i=start+1;i<=n;i++){
		ans+=digui(i,i,sm+a[i]);
		ans+=digui(mx,i,sm);
		ans%=998,244,353;
	}
	return ans;
}
void solveBF(){
	if(n<3){
		cout<<0;
		return;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return;
	}
	if(n<=20){
		long long ans=-1;
		for(long long i=1;i<=n-2;i++){
			ans=max(ans,digui(i,i,a[i]));
			ans%=998,244,353;
		}
		cout<<ans;
		return;
	}
}
void solve(){
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=500) solveBF();
	else solve();
	return 0;
}
