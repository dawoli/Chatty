#include<iostream>
#include<algorithm>
using namespace std;
int a[1145],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int r=a[1],x;
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	if(a[i]==r)
	x=n*m-i+1;
	cout<<x/m+1<<" ";
	if((x/m)%2==0)
	cout<<(x-1)%m+1;
	else 
	cout<<n-(x-1)%n;
	
} 
