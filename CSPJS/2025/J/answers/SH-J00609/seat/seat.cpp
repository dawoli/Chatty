#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c=0,r=0;
	cin>>n>>m;
	int a[m*n+1];
	int b=1;
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	for(int i=1;i<m*n;i++){
		if(a[0]<a[i])b++;
	}
	if(b%n==0)c=b/n;
	if(b%n!=0)c=b/n+1;
	if(c%2==0)r=n-(b-n*(c-1)-1);
	if(c%2==1)r=b-n*(c-1);
	cout<<c<<" "<<r;
	return 0;
}
