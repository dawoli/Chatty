#include<bits/stdc++.h>
using namespace std;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	int a[n],d[n];
	cin>>a[0];
	d[0]=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		d[i]=a[i] xor d[i-1];
	}
	return 0;
}
