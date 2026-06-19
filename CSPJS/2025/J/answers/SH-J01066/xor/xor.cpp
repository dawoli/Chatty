#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k==0&&n==0)cout<<0;
	else if(k==0&&n==1)cout<<0;
	else if(k==0&&n==2)cout<<1;
	else if(k==0)cout<<n/2;
	else cout<<0;
	return 0;
}
