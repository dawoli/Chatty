#include<bits/stdc++.h>
using namespace std;
int n,m,a,b=1,x,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		if(i==1) a=x;
		else{
			if(x>a) b++;
		}
	}
	l=b/n;
	r=(l&1?n-(b%n==0?b%n:b%n-1):b%n);
	l+=bool(b%n);
	cout<<l<<' '<<r;
	return 0;
}
//AC
