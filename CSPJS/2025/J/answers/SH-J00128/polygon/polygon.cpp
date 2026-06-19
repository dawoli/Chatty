#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005];
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n>3){
		int sum=0;
		long long c=2;
	}
	else{
		if ((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
}
