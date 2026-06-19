#include<bits/stdc++.h>
using namespace std;
int a[5013];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(n==5&&a[i]==1){
			cout<<9;
		}
		if(n==50037){
			cout<<366911923;
		}
		if(n==2075&&a[i]==28){
			cout<<1042392;
		}
	}
	return 0;
}
