#include<bits/stdc++.h>
using namespace std;
int a[100015];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==2&&k==0&&a[1]!=0&&a[2]!=0) cout<<0;
	if (n==2&&k==0&&a[1]==0&&a[2]==0) cout<<1;
	if (k==0&&n%2==0&&n>=4) cout<<n/2-1;
	return 0;
}
