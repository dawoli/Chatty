#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d=0,c,r;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0])
		{
			d++;
		}
	}
	if(d==0){
		cout<<1<<' '<<1;
		return 0;
	}
	if(d%n==0&&d!=0){
		r=n;
		c=d/n;
		cout<<c<<' '<<r;
	}
	else 
	{
		if((d/n+1)%2==1){
			c=d/n+1;
			r=d%n+1; 
			cout<<c<<' '<<r;
		}
		else{
			c=d/n+1;
			r=n-d%n;
			cout<<c<<' '<<r;
		}
	}
	return 0;
}
