#include<iostream>
using namespace std;
int n,m,a1,ai,rk;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr); 
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=1;i<n*m;i++)
		cin>>ai,rk+=ai>a1;
	cout<<rk/n+1<<" "<<(rk/n&1?n-rk%n:rk%n+1);
	return 0;
} 
