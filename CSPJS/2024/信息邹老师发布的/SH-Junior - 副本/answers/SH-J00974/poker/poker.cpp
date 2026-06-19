#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=60;
string a[N];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout); 
	ll n;
	cin>>n;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<52-min(52ll,unique(a+1,a+n+1)-a-1);
	return 0;
}
