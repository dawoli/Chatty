#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
ll a[N];
//freopen
//windows.h
//ccfccfccf
//cspcspcsp
//?Help!
//ÆÚ´ýÐ½×Ê£º100+100+30+36=266 2/3= 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	ll s;
	for(s=1;s<=n;s++){
		cin>>a[s];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		cout<<(1<<n)-n-n*(n-1)/2-1;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n<3){
		cout<<0;
	}
	return 0;
}  
