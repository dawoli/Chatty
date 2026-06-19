#include<bits/stdc++.h>
using namespace std;
int a[100015],cnt,b,M;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b+=a[i];
		M=max(M,a[i]);
	}
	if (b>2*M) cnt++;
	cout<<cnt;
	return 0;
}
