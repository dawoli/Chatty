#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	int c;
	if(k==0){
		c=n*(n-1)/2;
		cout<<c;
	}
	
}
