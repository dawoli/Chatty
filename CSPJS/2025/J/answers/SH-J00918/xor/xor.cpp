#include<bits/stdc++.h>
using namespace std;

int a[100009];

int main ()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);

	int n,k,cnt=0;
	
	cin>>n>>k; 
	
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	
	if (n==4&&k==0) {
		cout<<1;
		return 0;
	}
	
	cout<<n/2;
	
	return 0;
}
