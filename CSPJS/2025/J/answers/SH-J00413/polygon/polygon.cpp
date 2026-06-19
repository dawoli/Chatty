#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],mx=0,s=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(i>=3 && s>=2*mx) sum++;
	}
	cout<<sum;
	return 0;
}

