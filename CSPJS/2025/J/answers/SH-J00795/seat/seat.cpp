#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1009];
ll r,c,k;
ll n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>x[i];
	k=x[1];
	sort(x+1,x+1+m*n);
	for(int i=m*n;i>0;i--){
		if(x[i]==k){
			k=m*n+1-i;
			break;
		}
	}
	c=(k-1)/n+1;
	if(c%2==0){
		r=n-((k-1)%n);
	}
	else {
		r=k%n;
		if(r==0)
		r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
