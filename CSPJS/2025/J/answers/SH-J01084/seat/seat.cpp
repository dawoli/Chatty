#include <bits/stdc++.h>
using namespace std;
int n,m,x[109],b;
long a[10][10];
int f,d,c;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>x[i];
	}
	c=x[1];
	sort(x+1,x+m*n+1);
	for(int i=n*m;i>=1;--i){
		if(x[i]==c){
			b=m*n-i+1;
		}
	}
	if(b%n==0){
		f=b/m;
		if(f%2==0) d=1;
		else d=m;
	} 
	else {
		f=b/n+1;
		if(f%2==0) d=m-b%n+1;
		else d=b%n;
	}
	
	cout<<f<<" "<<d<<endl;
	return 0;
}
