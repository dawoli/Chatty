#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[20009],cnt,Max,ans,bit[20009];
bool OK(ll a){
	ll ni=0,cnti=0,maxi=0,cntj=0;
	while(a>1<<ni){ni++;}
	ll j=ni;
	while(a&&j){
		bit[j]=a%2;
		a/=2;
		j--;
	}
	for(ll i=1;i<=ni;i++){
		if(bit[i]==1){
			maxi=max(maxi,x[i]);
			cnti+=x[i];
			cntj++;
		}
	}
	if(cntj>=3&&cnti>2*maxi) return 1;
	else return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
		cnt+=x[i];
		Max=max(Max,x[i]);
	}
	if(n==3&&cnt>Max*2){
		cout<<"1";
		return 0;
	}
	else if(n==3){
		cout<<"0";
		return 0;
	}
	for(ll i=1;i<1<<n;i++){
		ans+=OK(i);
	} 
	cout<<ans;
	return 0;
}
