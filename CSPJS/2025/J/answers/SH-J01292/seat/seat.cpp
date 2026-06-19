#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],k,cnt=1,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=1;i<=n*m;i++){
		if(k<a[i])cnt++;
	}
	if(cnt%n==0){
		c=cnt/n;
		if((cnt/n)%2==1){
			r=n;
		}
		else r=1;
	}
	else{
		c=cnt/n+1;
		if((cnt/n)%2==0)r=cnt%n;
		if((cnt/n)%2==1)r=n-(cnt%n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
