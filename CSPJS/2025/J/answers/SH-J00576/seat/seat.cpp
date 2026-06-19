#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=109;
ll n,m,a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ll R=a[1],Rid=0;
	sort(a+1,a+1+n*m,greater<ll>() );
	for(int i=1;i<=n*m;i++)
		if(a[i]==R){
			Rid=i;
			break;
		}
	ll cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(cnt==Rid){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(cnt==Rid){
					cout<<i<<" "<<j<<endl;
					return 0;
				} 
			}
		}
	}
	return 0;
}

