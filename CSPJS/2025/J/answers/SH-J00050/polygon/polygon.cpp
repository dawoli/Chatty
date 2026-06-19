#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[11];
int n;
bool flag[11];

ll search(int k){
	if(k==n+1){
		int q=0,z=0,ma=0;
		for(int i=1;i<=n;i++){
			if(flag[i]){
				q++;
				z+=a[i];
				ma=max(a[i],ma);
			}
		}
		if(q>=3 && z>2*ma) return 1;
		else return 0;
	}
	flag[k]=1;
	ll ans1=search(k+1);
	flag[k]=0;
	ll ans2=search(k+1);
	return (ans1+ans2)%998244353;
}

void solve(){
	cin>>n;
	if(n<=3){
		if(n<3) cout<<0;
		else{
			int a,b,c;
			cin>>a>>b>>c;
			if(a<b) swap(a,b);
			if(a<c) swap(a,c);
			if(b+c>a) cout<<1;
			else cout<<0;
		}
	}
	else if(n<=20){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}	
		cout<<search(0)/2;
	}
	else{
		int a;
		ll k=1;
		for(int i=1;i<=n;i++){
			cin>>a;
			k*=2;
			k%=998244353;
		}
		cout<<k-1-n*(n-1)/2;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	
	return 0;
}

