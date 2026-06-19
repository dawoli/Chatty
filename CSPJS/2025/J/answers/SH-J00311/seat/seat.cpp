#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,R,l,h;
	cin>>n>>m;
	vector<ll> d(n*m),a(n*m);
	for(ll i=0;i<n*m;i++){
		cin>>a[i];
	}
	R=a[0];
	sort(a.begin(),a.end());
	int j=0;
	for(ll i=n*m-1;i>=0;i--){
		d[j]=a[i];
		j++;
	}
	for(ll i=0;i<n*m;i++){
		if(d[i]==R){
			l=i/n;
			if(l%2==0) h=i%n;
			if(l%2!=0) h=n-(i%n)-1;
			break;
		}
	}
	cout<<l+1<<" "<<h+1<<endl;
	return 0;
}
