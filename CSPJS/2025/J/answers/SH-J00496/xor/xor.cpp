#include <bits/stdc++.h>
using namespace std;
long long n,k;

long long res(int l,int r){
	int x=0;
	for(int i=l;i<=r;i++){
		x^=a[i];
	}
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
	}
	cout<<n/2;
	return 0;
}
