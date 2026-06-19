#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x,ans=0;
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		int y;
		cin>>y;
		ans+=(y>x);
	} 
	int c=ans/n+1,r=ans%n;
	cout<<c<<' ';
	if(c%2==0) cout<<n-r;
	else cout<<r+1;
	return 0;
}

