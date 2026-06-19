#include<bits/stdc++.h>
using namespace std;
int a[150],n,m,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1])
			c++;
	}
	cout<<(c-1)/n+1<<' ';
	c=(c-1)%(2*n)+1;
	if(c<=n)
		cout<<c;
	else
		cout<<2*n-c+1;
	return 0;
}
