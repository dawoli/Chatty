/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[101]={};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=10;j++)
			cin>>a[j];
		for(int j=1;j<=10;j++){
			ans=max(ans,a[j]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
