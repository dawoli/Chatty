#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans;
ll x[1009],ok[1009];
ll f[1009][1009];
void solve2(){				//10
	cout<<n/2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ppp=1;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]==1) ppp=1;
		else ppp=0;
	}
	if(k==0&&ppp){
		solve2();
		return 0;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(j+i>n+1) continue;
			f[i][j]=x[j];
			bool OK=1;
			for(ll p=j+1;p<i+j;p++){
				f[i][j]=f[i][j] xor x[p];
				if(ok[p]){
					OK=0;
					break;
				}
			}
			if(f[i][j]==k&&OK&&!ok[j]){
				ans++;
				for(ll p=j;p<j+i;p++)
					ok[p]=1;
			} 
		}
	}
	//for(ll i=1;i<=n;i++){
	//	for(ll j=1;j<=n;j++){
	//		if(j+i>n+1) continue;
	//		cout<<f[i][j];
	//	}
	//	cout<<endl;
	//}
	cout<<ans;
	return 0;
} 
