#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=19;
ll n,m,k,a[10009];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++) cin>>a[i];
	//求R排在第几名
	k=1;
	for(ll i=2;i<=n*m;i++) if(a[i]>a[1]) k++;
	//模拟
	ll pos=0;//现在是第几名 
	for(ll j=1;j<=m;j++){
		if(j%2==1){
			for(ll i=1;i<=n;i++){
				pos++;
				if(pos==k){
					cout<<j<<' '<<i<<endl;
					return 0;
				}
			}
		}
		else{
			for(ll i=n;i>=1;i--){
				pos++;
				if(pos==k){
					cout<<j<<' '<<i<<endl;
					return 0;
				}
			}
		}
	} 
	return 0;
}
