#include<bits/stdc++.h>
using namespace std;
int n,k,a[300];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<n;
	if(k==0)cout<<n/2;
	else cout<<n/k;
	return 0;
}
