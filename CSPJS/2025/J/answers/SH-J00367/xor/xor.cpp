#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=1;
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	return 0; 
} 
