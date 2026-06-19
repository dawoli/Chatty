#include <bits/stdc++.h>
using namespace std;
int a;
int ans;
int n,m;
int main( ){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>a)
			ans++;
	}
	int x=0,y=0;
	y=ans/n;
	ans%=n;
	if(y%2==0)
		x=ans+1;
	else
		x=n-ans;
	y++;
	cout<<y<<" "<<x;
	return 0;
}
