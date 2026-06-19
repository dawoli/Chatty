#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],x[N],sum;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1)	sum++;
	}
	x[1]=a[1];
	for(int i=2;i<=n;i++){
		x[i]=x[i-1]^a[i];
	}
	if(k==0)	cout << (n-1)/2;
	if(k==1)	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
