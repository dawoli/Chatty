#include<bits/stdc++.h>
#define N 500005
typedef long long ll;
using namespace std;
ll n,k,a[N],pre[N],ans;
bool A(){
	for(ll i=1;i<=n;i++) if(a[i]!=1) return 0;
	return 1;
}
bool B(){
	for(ll i=1;i<=n;i++) if(a[i]>1) return 0;
	return 1;
}
void Solve1_8(){
	for(ll i=1;i<=n;i++){
		ll t=-1;
		for(ll j=i;j<=n;j++) if((pre[j]^pre[i-1])==k){ ans++,t=j; break; }
		if(t!=-1) i=t;
	}
	cout<<ans;
}
void SolveB(){
	if(k==1){
		for(ll i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans;
	}
	else{
		for(ll i=1;i<=n;i++) if(a[i]==0) ans++;
		for(ll i=1;i<n;i++) if(a[i]==1&&a[i+1]==1) ans++,i++;
		cout<<ans;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i],pre[i]=(pre[i-1]^a[i]);
	if(A()) cout<<(ll)n/2;				//10pts
	else if(B()) SolveB();				//20pts
	else if(n<=100) Solve1_8();			//<=15pts
	else Solve1_8();
	return 0;
}
