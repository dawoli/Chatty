#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1);
	int location;
	for(int i=n*m;i>=1;i--){
		if(a[i]==t){
			location=n*m-i+1;
			break;
		}
	}
	int line;
	if(location%n==0){
		cout<<location/n<<" ";
		line=location/n;
	}
	else {
		cout<<location/n+1<<" ";
		line=location/n+1;
	}
	if(line%2!=0){
		if(location%n==0)cout<<n;
		else cout<<location%n;
	}
	else {
		if(location%n==0)cout<<1;
		else cout<<n-location%n+1;
	}
	return 0;
}
