#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ff(int x,int b){
	for (int i=x+1;i<=b;i++){
		if (a[i]!=a[i-1]){
			a[i]=1;
		}
		else{
			a[i]=0;
		} 
	}
	return a[b];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long s=0; 
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (ff(i,j)==k){
				s++;
			}
		}
	}
	cout<<s;
	return 0; 
}
