#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],cnt,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	cnt++;//cnt stands for R's rate
	c=(cnt-1)/n+1;
	if(c&1){
		r=cnt%n;
		if(r==0)r=n;
	}
	else{
		r=n-(cnt%n-1);
		if(r>n)r%=n;
	}
	cout<<c<<' '<<r;
	return 0;
}  
