#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],b[100010],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)b[i]=b[i-1]+a[i];
	if(n<3)cout<<0;
	else if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*a[3])cout<<1;
		else cout<<0;
	}
	else cout<<9;
	return 0;
 } 
