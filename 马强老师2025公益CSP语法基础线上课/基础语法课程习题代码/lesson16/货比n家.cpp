/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[101]={},maxn=0,minn=1000;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);		
		minn=min(minn,a[i]);
	}
	sort(a+1,a+1+n);//从小到大
	for(int i=n;i>0;i--)
		cout<<a[i]<<' ';
	cout<<endl;
	cout<<minn<<' '<<a[(n+1)/2]<<' '<<maxn;
	
	return 0;
}
