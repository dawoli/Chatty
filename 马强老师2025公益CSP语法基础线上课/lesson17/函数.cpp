/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	cout<<abs(-1)<<endl;
	cout<<abs(-3.14);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//TODO
		cout<<a[i]<<' ';
	}
	return 0;
}
