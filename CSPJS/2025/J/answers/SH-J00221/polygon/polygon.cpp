#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100001],ans=0,ans1=0;  
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i];
	if(a[i]==1) ans++;
	}
	sort(a,a+n);
	if(n<3){cout<<0;}
	if(n==3&&a[0]+a[1]>a[2]){cout<<1;}
	else if(ans==n) {
	for(int i=1;i<=n-2;i++){
		ans1+=i;
	}
		cout<<ans1;
}
	else cout<<0;

	return 0;
	
}
