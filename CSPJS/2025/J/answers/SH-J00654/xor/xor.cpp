#include<bits/stdc++.h>
using namespace std;
int n,k,l=1,sum;
int a[500005],b[500005];
int xorwow(int a,int b){
	return ((a|b)&(~(a&b)));
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		if(a[i]==k){
			sum++;
			l=i+1;
			continue;
		}
		for(int j=l;j<=i-1;j++){
			b[j]=xorwow(b[j], a[i]);
			if(b[j]==k){
				l=i+1;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
