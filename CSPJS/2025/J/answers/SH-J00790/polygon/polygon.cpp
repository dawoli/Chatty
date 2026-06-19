#include<bits/stdc++.h>
using namespace std;
int a[5050],cnt,ma;
int main() {
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma+=a[i];
	}
	sort(a+1,a+n);
	if(n==3){
		if(ma>(2*a[n]))cout<<1;
		else cout<<0;
		return 0;
	}
	return 0;
}
